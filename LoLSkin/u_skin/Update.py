# -*- coding:utf-8 -*-

import re
import os
import sys
import zipfile
import requests
import time


class Local:
    def __init__(self):
        self.version = None
        self.file_name = None

    def repair_language(self):
        print('修复翻译错误...')
        data = b"\xef\xbb\xbf\r\n[VN]\r\nFindFolder=\xc4\x90ang t\xc3\xacm Li\xc3\xaan Minh Huy\xe1\xbb\x81n Tho\xe1\xba\xa1i...\r\nOPEN_LOL=Ngay B\xc3\xa2y Gi\xe1\xbb\x9d,B\xe1\xba\xa1n h\xc3\xa3y v\xc3\xa0o Li\xc3\xaan Minh Huy\xe1\xbb\x81n Tho\xe1\xba\xa1i\r\nBACK=Quay L\xe1\xba\xa1i\r\nPrev=Quay L\xe1\xba\xa1i\r\nNext=Xem Ti\xe1\xba\xbfp\r\nActiveSkin=K\xc3\x8dCH HO\xe1\xba\xa0T\r\nACTIVATION_SUCCESS=K\xc3\xadch Ho\xe1\xba\xa1t %s Th\xc3\xa0nh C\xc3\xb4ng !\r\nUPDATE=\xc4\x90\xc3\xa3 c\xc3\xb3 b\xe1\xba\xa3n c\xe1\xba\xadp nh\xe1\xba\xadt m\xe1\xbb\x9bi!! B\xe1\xba\xa1n h\xc3\xa3y v\xc3\xa0o http://modskinpro.com v\xc3\xa0 t\xe1\xba\xa3i l\xe1\xba\xa1i b\xe1\xba\xa3n m\xe1\xbb\x9bi nh\xe1\xba\xa5t nh\xc3\xa9.\r\n[EN]\r\nFindFolder=Finding League of Legend...\r\nOPEN_LOL=Now, you go to the League of Legend....\r\nBACK=Back\r\nPrev=Back\r\nNext=Next\r\nActiveSkin=ACTIVE SKIN\r\nACTIVATION_SUCCESS=Active %s Successful !\r\nUPDATE=There is a new update !!Please, You go to http://leagueskin.net and download the latest version.\r\n[AR]\r\nFindFolder=Finding League of Legend...\r\nOPEN_LOL=Ahora, usted va a la Liga de la Leyenda ....\r\nBACK=Espalda\r\nPrev=Espalda\r\nNext=Siguiente\r\nActiveSkin=PIEL ACTIVA\r\n[BG]\r\nFindFolder=\xd1\x82\xd1\x8a\xd1\x80\xd1\x81\xd0\xb5\xd0\xbd\xd0\xb5 League of Legend...\r\nOPEN_LOL=Agora, voc\xc3\xaa vai para a League of Legends\r\nBACK=\xd0\xbd\xd0\xb0\xd0\xb7\xd0\xb0\xd0\xb4\r\nPrev=\xd0\xbd\xd0\xb0\xd0\xb7\xd0\xb0\xd0\xb4\r\nNext=\xd0\xb4\xd0\xbe\r\nActiveSkin=\xd0\xb0\xd0\xba\xd1\x82\xd0\xb8\xd0\xb2\xd0\xb5\xd0\xbd\r\nACTIVATION_SUCCESS=\xd0\xb0\xd0\xba\xd1\x82\xd0\xb8\xd0\xb2\xd0\xb5\xd0\xbd %s \xd0\xa3\xd1\x81\xd0\xbf\xd0\xb5\xd1\x88\xd0\xbd\xd0\xbe!\r\n[CZ]\r\nFindFolder=vyhled\xc3\xa1v\xc3\xa1n\xc3\xad League of Legend...\r\nOPEN_LOL=Te\xc4\x8f jdete do League of Legend....\r\nBACK=zp\xc4\x9bt\r\nPrev=zp\xc4\x9bt\r\nNext=dal\xc5\xa1\xc3\xad\r\nActiveSkin=Aktivn\xc3\xad\r\nACTIVATION_SUCCESS=Aktivn\xc3\xad %s \xc3\x9asp\xc4\x9b\xc5\xa1n\xc3\xa9 !\r\n[DE]\r\nFindFolder=Suche League of Legend...\r\nOPEN_LOL=Nun gehen Sie in die League of Legend....\r\nBACK=zur\xc3\xbcck\r\nPrev=zur\xc3\xbcck\r\nNext=n\xc3\xa4chste\r\nActiveSkin=Aktiv\r\nACTIVATION_SUCCESS=Aktiv %s erfolgreich!\r\n[GR]\r\nFindFolder=\xce\xb1\xce\xbd\xce\xb1\xce\xb6\xce\xae\xcf\x84\xce\xb7\xcf\x83\xce\xb7 League of Legend...\r\nOPEN_LOL=\xce\xa4\xcf\x8e\xcf\x81\xce\xb1, \xce\xbc\xcf\x80\xce\xbf\xcf\x81\xce\xb5\xce\xaf\xcf\x84\xce\xb5 \xce\xbd\xce\xb1 \xcf\x80\xce\xac\xcf\x84\xce\xb5 \xcf\x83\xcf\x84\xce\xbf League of Legend....\r\nBACK=\xcf\x80\xce\xaf\xcf\x83\xcf\x89\r\nPrev=\xcf\x80\xce\xaf\xcf\x83\xcf\x89\r\nNext=\xce\xb5\xcf\x80\xcf\x8c\xce\xbc\xce\xb5\xce\xbd\xce\xbf\xcf\x82\r\nActiveSkin=\xce\x95\xce\xbd\xce\xb5\xcf\x81\xce\xb3\xce\xac\r\nACTIVATION_SUCCESS=\xce\x95\xce\xbd\xce\xb5\xcf\x81\xce\xb3\xce\xac %s \xce\x95\xcf\x80\xce\xb9\xcf\x84\xcf\x85\xcf\x87\xce\xae\xcf\x82 !\r\n[ES]\r\nFindFolder=Buscar League of Legends...\r\nOPEN_LOL=Ahora, ves a League of legends...\r\nBACK=Atr\xc3\xa1s\r\nPrev=Atr\xc3\xa1s\r\nNext=Siguiente\r\nActiveSkin=Skin activa\r\nACTIVATION_SUCCESS=\xc2\xa1Activaci\xc3\xb3n %s exitosa!\r\n[FR]\r\nFindFolder=Recherche League of Legend...\r\nOPEN_LOL=Maintenant, vous allez \xc3\xa0 la League of Legends....\r\nBACK=arri\xc3\xa8re\r\nPrev=arri\xc3\xa8re\r\nNext=suivant\r\nActiveSkin=Actif\r\nACTIVATION_SUCCESS=Actif %s Succ\xc3\xa8s!\r\n[HU]\r\nFindFolder=Keres\xc3\xa9s League of Legend...\r\nOPEN_LOL=Most megy a League of Legends....\r\nBACK=vissza\r\nPrev=vissza\r\nNext=k\xc3\xb6vetkez\xc5\x91\r\nActiveSkin=Akt\xc3\xadv\r\nACTIVATION_SUCCESS=Akt\xc3\xadv %s Sikeres !\r\n[IT]\r\nFindFolder=Cercando League of Legends...\r\nOPEN_LOL=Ora, si va al League of Legends....\r\nBACK=indietro\r\nPrev=indietro\r\nNext=prossimo\r\nActiveSkin=Attivo\r\nACTIVATION_SUCCESS=Attivo %s di successo!\r\n[JP]\r\nFindFolder=\xe4\xbc\x9d\xe8\xaa\xac\xe3\x81\xae\xe3\x83\xaa\xe3\x83\xbc\xe3\x82\xb0\xe3\x82\x92\xe6\xa4\x9c\xe7\xb4\xa2...\r\nOPEN_LOL=\xe3\x81\x95\xe3\x81\xa6\xe3\x80\x81\xe3\x81\x82\xe3\x81\xaa\xe3\x81\x9f\xe3\x81\xaf\xe4\xbc\x9d\xe8\xaa\xac\xe3\x81\xae\xe3\x83\xaa\xe3\x83\xbc\xe3\x82\xb0\xe3\x81\xab\xe8\xa1\x8c\xe3\x81\x8d\xe3\x81\xbe\xe3\x81\x99....\r\nBACK=\xe3\x83\x90\xe3\x83\x83\xe3\x82\xaf\r\nPrev=\xe3\x83\x90\xe3\x83\x83\xe3\x82\xaf\r\nNext=\xe6\xac\xa1\xe3\x81\xae\r\nActiveSkin=\xe3\x82\xa2\xe3\x82\xaf\xe3\x83\x86\xe3\x82\xa3\xe3\x83\x96\r\nACTIVATION_SUCCESS=\xe3\x82\xa2\xe3\x82\xaf\xe3\x83\x86\xe3\x82\xa3\xe3\x83\x96 %s \xe6\x88\x90\xe5\x8a\x9f\xef\xbc\x81\r\n[KR]\r\nFindFolder=\xec\xa0\x84\xec\x84\xa4\xec\x9d\x98 \xeb\xa6\xac\xea\xb7\xb8 \xea\xb2\x80\xec\x83\x89...\r\nOPEN_LOL=\xec\xa7\x80\xea\xb8\x88, \xeb\x8b\xb9\xec\x8b\xa0\xec\x9d\x80 \xec\xa0\x84\xec\x84\xa4\xec\x9d\x98 \xeb\xa6\xac\xea\xb7\xb8\xeb\xa1\x9c \xec\x9d\xb4\xeb\x8f\x99....\r\nBACK=\xeb\xb0\xb1\r\nPrev=\xeb\xb0\xb1\r\nNext=\xeb\x8b\xa4\xec\x9d\x8c\r\nActiveSkin=\xec\x95\xa1\xed\x8b\xb0\xeb\xb8\x8c\r\nACTIVATION_SUCCESS=\xec\x95\xa1\xed\x8b\xb0\xeb\xb8\x8c %s \xec\x84\xb1\xea\xb3\xb5!\r\n[NL]\r\nFindFolder=Zoeken League of Legend...\r\nOPEN_LOL=Nu, ga je naar de League of Legends....\r\nBACK=terug\r\nPrev=volgende\r\nNext=volgende\r\nActiveSkin=Actief\r\nACTIVATION_SUCCESS=Actief %s Geslaagd!\r\n[PL]\r\nFindFolder=Wyszukiwanie League of Legends...\r\nOPEN_LOL=Teraz przejd\xc5\xba do League of Legends....\r\nBACK=z powrotem\r\nPrev=z powrotem\r\nNext=nast\xc4\x99pny\r\nActiveSkin=aktywny\r\nACTIVATION_SUCCESS=Aktywny %s Sukces!\r\n[BR]\r\nFindFolder=Pesquisando League of Legend...\r\nOPEN_LOL=Agora, voc\xc3\xaa vai para a League of Legends....\r\nBACK=de volta\r\nPrev=de volta\r\nNext=pr\xc3\xb3ximo\r\nActiveSkin=Ativo\r\nACTIVATION_SUCCESS=Ativo %s com sucesso!\r\n[RO]\r\nFindFolder=C\xc4\x83utarea League of Legend...\r\nOPEN_LOL=Acum, tu du-te la League of Legends....\r\nBACK=\xc3\xaenapoi\r\nPrev=\xc3\xaenapoi\r\nNext=urm\xc4\x83tor\r\nActiveSkin=Activ\xc4\x83\r\nACTIVATION_SUCCESS=Activ\xc4\x83 %s succes!\r\n[RU]\r\nFindFolder=\xd0\x9f\xd0\xbe\xd0\xb8\xd1\x81\xd0\xba \xd0\x9b\xd0\xb8\xd0\xb3\xd0\xb0 \xd0\x9b\xd0\xb5\xd0\xb3\xd0\xb5\xd0\xbd\xd0\xb4\xd0\xb0...\r\nOPEN_LOL=\xd0\xa2\xd0\xb5\xd0\xbf\xd0\xb5\xd1\x80\xd1\x8c, \xd0\xb2\xd1\x8b \xd0\xb8\xd0\xb4\xd0\xb5\xd1\x82\xd0\xb5 \xd0\xb2 \xd0\x9b\xd0\xb8\xd0\xb3\xd1\x83 \xd0\x9b\xd0\xb5\xd0\xb3\xd0\xb5\xd0\xbd\xd0\xb4....\r\nBACK=\xd0\xbd\xd0\xb0\xd0\xb7\xd0\xb0\xd0\xb4\r\nPrev=\xd0\xbd\xd0\xb0\xd0\xb7\xd0\xb0\xd0\xb4\r\nNext=\xd1\x81\xd0\xbb\xd0\xb5\xd0\xb4\xd1\x83\xd1\x8e\xd1\x89\xd0\xb8\xd0\xb9\r\nActiveSkin=\xd0\xb0\xd0\xba\xd1\x82\xd0\xb8\xd0\xb2\xd0\xbd\xd1\x8b\xd0\xb9\r\nACTIVATION_SUCCESS=\xd0\xb0\xd0\xba\xd1\x82\xd0\xb8\xd0\xb2\xd0\xbd\xd1\x8b\xd0\xb9 %s \xd0\xa3\xd1\x81\xd0\xbf\xd0\xb5\xd1\x88\xd0\xbd\xd1\x8b\xd0\xb9!\r\n[TH]\r\nFindFolder=\xe0\xb8\x81\xe0\xb8\xb3\xe0\xb8\xa5\xe0\xb8\xb1\xe0\xb8\x87\xe0\xb8\xa1\xe0\xb8\xad\xe0\xb8\x87\xe0\xb8\xab\xe0\xb8\xb2 League of Legend...\r\nOPEN_LOL=\xe0\xb8\x95\xe0\xb8\xad\xe0\xb8\x99\xe0\xb8\x99\xe0\xb8\xb5\xe0\xb9\x89\xe0\xb8\x84\xe0\xb8\xb8\xe0\xb8\x93\xe0\xb9\x84\xe0\xb8\x9b\xe0\xb8\x97\xe0\xb8\xb5\xe0\xb9\x88\xe0\xb8\xa5\xe0\xb8\xb5\xe0\xb8\x81\xe0\xb8\x82\xe0\xb8\xad\xe0\xb8\x87\xe0\xb8\x95\xe0\xb8\xb3\xe0\xb8\x99\xe0\xb8\xb2\xe0\xb8\x99\r\nBACK=\xe0\xb8\x81\xe0\xb8\xa5\xe0\xb8\xb1\xe0\xb8\x9a\r\nPrev=\xe0\xb8\x81\xe0\xb8\xa5\xe0\xb8\xb1\xe0\xb8\x9a\r\nNext=\xe0\xb8\x95\xe0\xb9\x88\xe0\xb8\xad\xe0\xb9\x84\xe0\xb8\x9b\r\nActiveSkin=\xe0\xb9\x80\xe0\xb8\x9b\xe0\xb8\xb4\xe0\xb8\x94\xe0\xb9\x83\xe0\xb8\x8a\xe0\xb9\x89\xe0\xb8\x87\xe0\xb8\xb2\xe0\xb8\x99\r\nACTIVATION_SUCCESS=\xe0\xb9\x80\xe0\xb8\x9b\xe0\xb8\xb4\xe0\xb8\x94\xe0\xb9\x83\xe0\xb8\x8a\xe0\xb9\x89\xe0\xb8\x87\xe0\xb8\xb2\xe0\xb8\x99 %s \xe0\xb8\x97\xe0\xb8\xb5\xe0\xb9\x88\xe0\xb8\x9b\xe0\xb8\xa3\xe0\xb8\xb0\xe0\xb8\xaa\xe0\xb8\x9a\xe0\xb8\x84\xe0\xb8\xa7\xe0\xb8\xb2\xe0\xb8\xa1\xe0\xb8\xaa\xe0\xb8\xb3\xe0\xb9\x80\xe0\xb8\xa3\xe0\xb9\x87\xe0\xb8\x88 !\r\n[TR]\r\nFindFolder=Efsane Ligi aran\xc4\xb1yor...\r\nOPEN_LOL=\xc5\x9eimdi, Efsaneler Ligi gitmek....\r\nBACK=geri\r\nPrev=geri\r\nNext=sonraki\r\nActiveSkin=Aktif\r\nACTIVATION_SUCCESS=Aktif %s Ba\xc5\x9far\xc4\xb1l\xc4\xb1!\r\n[CN]\r\nFindFolder=\xe6\xad\xa3\xe5\x9c\xa8\xe6\x9f\xa5\xe6\x89\xbe\xe8\x8b\xb1\xe9\x9b\x84\xe8\x81\x94\xe7\x9b\x9f\xe7\x9a\x84\xe8\xb7\xaf\xe5\xbe\x84...\r\nOPEN_LOL=\xe6\xad\xa3\xe5\x9c\xa8\xe6\x89\x93\xe5\xbc\x80\xe4\xbd\xa0\xe7\x9a\x84\xe8\x8b\xb1\xe9\x9b\x84\xe8\x81\x94\xe7\x9b\x9f....\r\nBACK=\xe8\xbf\x94\xe5\x9b\x9e\r\nPrev=\xe8\xbf\x94\xe5\x9b\x9e\r\nNext=\xe4\xb8\x8b\xe4\xb8\x80\xe6\xad\xa5\r\nActiveSkin=\xe6\x8c\x82\xe8\xbd\xbd\r\nACTIVATION_SUCCESS=\xe6\x8c\x82\xe8\xbd\xbd %s \xe6\x88\x90\xe5\x8a\x9f\xef\xbc\x81\r\n[TW]\r\nFindFolder=\xe5\xb0\x8b\xe6\x89\xbe\xe8\x8b\xb1\xe9\x9b\x84\xe8\x81\xaf\xe7\x9b\x9f...\r\nOPEN_LOL=\xe7\x8f\xbe\xe5\x9c\xa8\xef\xbc\x8c\xe4\xbd\xa0\xe5\x8e\xbb\xe5\x82\xb3\xe5\xa5\x87\xe8\x81\xaf\xe7\x9b\x9f....\r\nBACK=\xe8\xbf\x94\xe5\x9b\x9e\r\nPrev=\xe8\xbf\x94\xe5\x9b\x9e\r\nNext=\xe4\xb8\x8b\xe4\xb8\x80\xe6\xad\xa5\r\nActiveSkin=\xe6\xb4\xbb\xe5\x8b\x95\xe7\x9a\xae\xe8\x86\x9a\r\nACTIVATION_SUCCESS=\xe6\xb4\xbb\xe5\x8b\x95 %s \xe6\x88\x90\xe5\x8a\x9f\xef\xbc\x81\r\n[ID]\r\nFindFolder=Mencari League of Legend ...\r\nOPEN_LOL=Sekarang, Anda pergi ke Liga Legenda ....\r\nBACK=Kembali\r\nPrev=Kembali\r\nNext=Berikutnya\r\nActiveSkin=ACTIVE KULIT\r\nACTIVATION_SUCCESS=Active %s Sukses!'"
        try:
            with open('C:\\Fraps\\data\\Default\\Language.ini', 'wb') as f:
                f.write(data)
                f.close()
        except:
            print('找不到文件"C:\Fraps\data\Default\Language.ini"')
        print('修复完成.')

    def get_local_version(self):
        path = 'C:\\Fraps'
        rec = re.compile(r'LOLPRO\s+\d+\.\d+\.exe')

        try:
            dirs = os.listdir(path)
        except:
            print('找不到指定目录"C:\Fraps"')
        else:
            for i in dirs:
                if rec.match(i):
                    rec = re.compile(r'\d+\.\d+')
                    self.version = rec.search(i).group()
                    break

        if not self.version:
            print('无法获取当前电脑上LeagueSkin的版本号.')

    def uncompression(self):
        print('开始解压文件...')
        try:
            with zipfile.ZipFile('./new_version.zip') as zfile:
                zfile.extractall()
        except zipfile.BadZipFile:
            print('压缩文件损坏, 请重新下载.')
        else:
            print('解压完成.')

    def del_old_version(self):
        try:
            os.system("rd/s/q C:\\Fraps")
        except:
            print('无法删除旧版文件.(若此前未使用过LeagueSkin请无视本错误)')

    def run_leagueskin(self):
        rec = re.compile(r'LOLPRO\s+\d+\.\d+\.exe')
        for i in os.listdir('./'):
            if rec.match(i):
                self.file_name = rec.match(i).group()
        print('正在运行最新版本的LeagueSkin.')
        os.system('"%s"' % self.file_name)

    def _run_leagueskin(self):
        rec = re.compile(r'LOLPRO\s+\d+\.\d+\.exe')
        for i in os.listdir('C:\\Fraps'):
            if rec.match(i):
                self.file_name = rec.match(i).group()
        print('正在运行最新版本的LeagueSkin.')
        os.system('C:\\Fraps\\"%s"' % self.file_name)

    def reset(self):
        file_path = os.path.dirname(os.path.abspath(__file__))
        try:
            os.remove("%s\\data.lol" % file_path)
            os.remove('%s\\%s' % (file_path, self.file_name))
            os.remove('%s\\new_version.zip' % file_path)
        except:
            print('无法删除更新残留文件.')
        else:
            print('已删除更新残留文件.语言文件错误将于下次运行时修复.')

class Network:
    def __init__(self):
        url = 'http://leagueskin.net/p/download-mod-skin-lol-pro-2016-chn'

        self.tab = requests.get(url=url)
        self.version = None
        self.download_url = None

    def get_network_version(self):
        rec = re.compile(r'DOWNLOAD\sLOL\sPRO\s\d+\.\d+\shere')
        try:
            str = rec.search(self.tab.text).group()
        except:
            print('无法获取最新LeagueSkin的版本号.')
        else:
            rec = re.compile(r'\d+\.\d+')
            self.version = rec.search(str).group()

    def get_download_url(self):
        rec = re.compile(r'http://dl2\.modskinpro\.com/LEAGUESKIN_\d+\.\d+\.zip\?update=\d+')
        try:
            self.download_url = rec.search(self.tab.text).group()
        except:
            print('无法获取新版本的下载链接.')

    def download_update(self):
        print('开始下载新版本...')
        download_tab = requests.get(self.download_url)
        try:
            total_size = int(download_tab.headers['Content-Length'])
            temp_size = 0

            with open('new_version.zip', "wb") as f:
                for chunk in download_tab.iter_content(chunk_size=64):
                    if chunk:
                        temp_size += len(chunk)
                        f.write(chunk)
                        f.flush()

                        done = int(50 * temp_size / total_size)

                        sys.stdout.write(
                            "\r[%s%s] %d%%" % ('█' * done, ' ' * (50 - done), 100 * temp_size / total_size))
                        sys.stdout.flush()
            print()
        except:
            print('下载失败.')
        else:
            print('下载完成.')

if __name__ == '__main__':
    print('该程序基于Python3.6.6开发, 用于检测并更新LeagueSkin;')
    print('使用它, 可以最大限度的避免因软件未及时更新而导致的其他后果(封号, 无法使用等);')
    print('兴趣使然的小玩意')
    a = Local()
    a.get_local_version()
    b = Network()
    b.get_network_version()

    print('当前版本:%s' % a.version)
    print('服务器版本:%s' % b.version)

    if a.version == b.version:
        print('无需更新.')
        print('------------------------------------------')
        a.repair_language()
        print('------------------------------------------')
        a._run_leagueskin()
        print('------------------------------------------')
    else:
        print('检测到有新版本.')
        print('------------------------------------------')
        b.get_download_url()
        b.download_update()
        print('------------------------------------------')
        a.uncompression()
        print('------------------------------------------')
        a.del_old_version()
        a.run_leagueskin()
        print('------------------------------------------')
        time.sleep(4)
        a.reset()
        print('------------------------------------------')