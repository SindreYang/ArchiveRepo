
# ====================== 自定义宏 产品信息==============================
!define PRODUCT_NAME           		"MyApp"
!define PRODUCT_PATHNAME           	"MyApp"     #安装卸载项用到的KEY
!define INSTALL_APPEND_PATH         "MyApp"     #安装路径追加的名称 
!define INSTALL_DEFALT_SETUPPATH    ""       #默认生成的安装路径 
!define EXE_NAME               		"MyApp.exe" # 指定主运行程序，快捷方式也是用此程序生成
!define PRODUCT_VERSION        		"1.0.0.0"
!define PRODUCT_PUBLISHER      		"F:\My_Github\py2nsis\examples\qt\SindreYang"
!define PRODUCT_LEGAL          		""${PRODUCT_PUBLISHER} Copyright（c）2023""
!define INSTALL_OUTPUT_NAME    		"MyApp_V1.0.0.0.exe"

# ====================== 自定义宏 安装信息==============================
!define INSTALL_7Z_PATH 	   		"F:\My_Github\py2nsis\examples\qt\app.7z"
!define INSTALL_7Z_NAME 	   		"app.7z"
!define INSTALL_RES_PATH       		"skin.zip"
!define INSTALL_LICENCE_FILENAME    "F:\My_Github\py2nsis\examples\qt\licence.rtf"
!define INSTALL_ICO 				"F:\My_Github\py2nsis\examples\qt\myapp.ico"


!include "ui.nsh"

# ==================== NSIS属性 ================================

# 针对Vista和win7 的UAC进行权限请求.
# RequestExecutionLevel none|user|highest|admin
RequestExecutionLevel admin

#SetCompressor zlib

; 安装包名字.
Name "${PRODUCT_NAME}"

# 安装程序文件名.

OutFile "F:\My_Github\py2nsis\examples\qt\MyApp_V1.0.0.0.exe"

InstallDir "1"

# 安装和卸载程序图标
Icon              "${INSTALL_ICO}"
UninstallIcon     "uninst.ico"

        
        