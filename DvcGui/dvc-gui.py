import sys
import os
from subprocess import call, STDOUT
import logging

from PyQt5.QtWidgets import QMainWindow, QPushButton, QApplication, QFileDialog, QToolTip, QInputDialog, QLineEdit, QMessageBox
from PyQt5.QtGui import QIcon



class DVCGui(QMainWindow):
    
    def __init__(self):
        super().__init__()
        self.check_whether_git('.')
        self.check_whether_dvc()
        self.check_remote_dvc()
        self.current_dir = os.getcwd()
        self.initUI()
        

    def initUI(self):

        self.statusBar()
        self.setGeometry(100, 100, 500, 300)
        self.setWindowTitle('Theresas DVC GUI')
        self.setWindowIcon(QIcon('./www/logo.png')) 
        self.statusBar().showMessage(f'{self.current_dir} was selected - git {self.git} - dvc {self.dvc}')
        
        btn_dir = QPushButton("Choose your project", self)
        btn_dir.resize(400, 25)
        btn_dir.move(30, 15)
        btn_dir.setToolTip("Switch to your project.")
        btn_dir.clicked.connect(self.change_dir)

        btn_init = QPushButton("dvc init", self)
        btn_init.resize(200, 25)
        btn_init.move(30, 70)
        btn_init.setToolTip("This initializes a DVC project on a directory.")
        btn_init.clicked.connect(self.dvc_init) 

        btn_pull = QPushButton("dvc pull", self)   
        btn_pull.resize(200, 25)     
        btn_pull.move(30, 100)
        btn_pull.setToolTip("Downloads missing files and directories from remote storage to the cache based on DVC-files in the workspace.")
        btn_pull.clicked.connect(self.dvc_pull)

        btn_add = QPushButton("dvc add", self)
        btn_add.resize(200, 25)     
        btn_add.move(30, 130)
        btn_add.setToolTip("Take one or more data files under DVC control.")
        btn_add.clicked.connect(self.dvc_add)

        btn_commit = QPushButton("dvc commit", self)
        btn_commit.resize(200, 25)     
        btn_commit.move(30, 160)
        btn_commit.setToolTip("Record changes to the repository by updating DVC-files and saving outputs to the cache.")
        btn_commit.clicked.connect(self.dvc_commit)

        btn_push = QPushButton("dvc push", self)
        btn_push.resize(200, 25)
        btn_push.move(30, 190)
        btn_push.setToolTip("Uploads files and directories under DVC control to the remote storage.")
        btn_push.clicked.connect(self.dvc_push)

        btn_gc = QPushButton("dvc gc", self)
        btn_gc.resize(200, 25)
        btn_gc.move(30, 240)
        btn_gc.setToolTip("Remove unused objects from cache or remote storage.")
        btn_gc.clicked.connect(self.dvc_gc)

        btn_remove = QPushButton("dvc remove", self)
        btn_remove.resize(200, 25)
        btn_remove.move(250, 240)
        btn_remove.setToolTip("Removes all DVC files and directories from a DVC project.")
        btn_remove.clicked.connect(self.dvc_remove)

        btn_remote_list = QPushButton("dvc remote list", self)
        btn_remote_list.resize(200, 25)
        btn_remote_list.move(250, 70)
        btn_remote_list.setToolTip("Show all available data remotes.")
        btn_remote_list.clicked.connect(self.list_remote)

        btn_remote_add = QPushButton("dvc remote add", self)
        btn_remote_add.resize(200, 25)             
        btn_remote_add.move(250, 100)
        btn_remote_add.setToolTip("Add a new data remote")
        btn_remote_add.clicked.connect(self.add_remote)

        btn_remote_remove = QPushButton("dvc remote remove", self)
        btn_remote_remove.resize(200, 25)             
        btn_remote_remove.move(250, 130)
        btn_remote_remove.setToolTip("Remove a data remotes")
        btn_remote_remove.clicked.connect(self.remove_remote)

        self.show()


    def dvc_gc(self):

        if self.dvc:
            os.system(f'dvc gc -f')
            self.statusBar().showMessage(f'objects from cache have been removed')
        else: 
            self.statusBar().showMessage(f'not a dvc repository')            


    def remove_remote(self):

        if self.remote:
            os.system(f'dvc remote remove {self.remote_name}')
            self.statusBar().showMessage(f'{self.remote_name} removed')
        else: 
            self.statusBar().showMessage(f'no remote defined - nothing to remove')


    def list_remote(self):
        remote = os.popen('dvc remote list').read()

        if remote != '':
            QMessageBox.about(self, "Remotes", f"{remote}")
        else: 
            QMessageBox.about(self, "Remotes", "No remotes found")


    def add_remote(self):

        self.check_remote_dvc()

        if self.remote:
            self.statusBar().showMessage(f'you already have a remote defined: {self.remote_name}')

        else:
            dialog = QInputDialog()
            self.remote_name, ok_pressed = dialog.getText(self, "Remote", "Name of the remote", QLineEdit.Normal, "")
            self.remote_path, ok_pressed = dialog.getText(self, "Add remote", "Add your remote data storage, can be an SSH, S3 path, Azure, \nGoogle Cloud address, Aliyun OSS, local directory, etc.", QLineEdit.Normal, "")

            if ok_pressed:

                self.check_whether_git(self.current_dir)
                self.check_whether_dvc()

                if self.git and self.dvc:

                    logging.info(f'{self.remote_name} was set as remote name')
                    logging.info(f'{self.remote_path} was set as remote path') 

                    os.system(f'dvc remote add {self.remote_name} {self.remote_path}')
                    self.statusBar().showMessage(f'{self.remote_name} added as a remote')
                    self.remote = True

                else: 
                    self.statusBar().showMessage(f'init as git and dvc first, before setting up a remote')


    def check_remote_dvc(self):
        
        remote = os.popen('dvc remote list').read()
        
        if remote != '':
            self.remote = True
            self.remote_name = remote.split()[0]
            self.remote_path = remote.split()[1]
        else:
            self.remote = False


    def check_whether_git(self, path):

        if call(["git", "-C", path, "status"], stderr=STDOUT, stdout=open(os.devnull, 'w')) != 0:
            self.git = False
            logging.info("fail - current directory is not a git repository")
        else:
            self.git = True
            logging.info("success - current directory is a git repository")


    def check_whether_dvc(self):
        try:

            if call(["dvc", "status"], stderr=STDOUT, stdout=open(os.devnull, 'w')) != 0:
                self.dvc = False
                logging.info("fail - dvc not yet initialized")
            else:
                self.dvc = True
                logging.info("sucess - dvc is already initialized")
        except Exception as e:
            print(e)

        
    def change_dir(self):

        dialog = QFileDialog()
        current_dir = dialog.getExistingDirectory(self, 'Select your project directory')
        
        if current_dir:
            os.chdir(current_dir)
            self.current_dir = current_dir
            logging.info(f'current directory is: {os.getcwd()}')

            self.check_whether_git(current_dir)
            self.check_whether_dvc()
            self.check_remote_dvc()
            self.statusBar().showMessage(f'{current_dir} was selected - git {self.git} - dvc {self.dvc}')

        else: 
            self.statusBar().showMessage('no directory selected')


    def dvc_commit(self):
        
        if self.dvc:
            os.system(f"dvc commit -f")
            self.statusBar().showMessage(f'saved the changes into the cache')
        
        else:
            self.statusBar().showMessage('not a dvc repository')


    def dvc_add(self):
        
        if self.dvc:
            dialog = QFileDialog()
            file_names, _ = dialog.getOpenFileNames(self,"QFileDialog.getOpenFileNames()", self.current_dir, "All Files (*)")

            if file_names:
                for f in file_names:
                    logging.info(f'adding {f} to dvc')
                    os.system(f"dvc add {f}")
                self.statusBar().showMessage(f'{len(file_names)} file(s) added - do not forget to track changes in git')
        
        else:
            self.statusBar().showMessage('not a dvc repository')


    def dvc_init(self):

        self.check_whether_dvc()

        if self.dvc:
            self.statusBar().showMessage(f'{self.current_dir} already a DVC repo')
        elif self.git:
            os.system("dvc init")
            self.statusBar().showMessage(f'{self.current_dir} initialized')
        else: 
            self.statusBar().showMessage('not a git repository, create one and try dvc init again')


    def dvc_pull(self):

        if self.remote:
            os.system(f"dvc pull --remote {self.remote_name}")
            self.statusBar().showMessage('changes have been pulled')
        else:
            self.statusBar().showMessage('no remote defined yet')


    def dvc_push(self):

        if self.remote:
            os.system(f"dvc push --remote {self.remote_name}")
            self.statusBar().showMessage('pushed to remote')
        else: 
            self.statusBar().showMessage('no remote defined yet')

    
    def dvc_remove(self):

        if self.dvc:
            os.system("dvc destroy -f")
            self.statusBar().showMessage('all DVC files and directories removed')
            self.dvc = False
        else: 
            self.statusBar().showMessage('not a DVC project, nothing to remove')



if __name__ == '__main__':
    
    app = QApplication(sys.argv)
    d = DVCGui()
    
    sys.exit(app.exec_())