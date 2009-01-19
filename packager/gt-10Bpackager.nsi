; Script generated by the HM NIS Edit Script Wizard.

; HM NIS Edit Wizard helper defines
!define PRODUCT_NAME "GT-10BFxFloorBoard"
!define PRODUCT_VERSION "20090118"
!define PRODUCT_PUBLISHER "gumtownbassman"
!define PRODUCT_WEB_SITE "http://www.gtx.tinfoilmusic.net"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\GT-10BFxFloorBoard.exe"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"

SetCompressor lzma

; MUI 1.67 compatible ------
!include "MUI.nsh"

; MUI Settings
!define MUI_ABORTWARNING
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\orange-install.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\orange-uninstall.ico"

; Welcome page
!insertmacro MUI_PAGE_WELCOME
; License page
!insertmacro MUI_PAGE_LICENSE "license.txt"
; Directory page
!insertmacro MUI_PAGE_DIRECTORY
; Instfiles page
!insertmacro MUI_PAGE_INSTFILES
; Finish page
!define MUI_FINISHPAGE_RUN "$INSTDIR\GT-10BFxFloorBoard.exe"
!define MUI_FINISHPAGE_SHOWREADME "$INSTDIR\GT-10BFxFloorBoard_help_files\readme.txt"
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages
!insertmacro MUI_UNPAGE_INSTFILES

; Language files
!insertmacro MUI_LANGUAGE "English"

; Reserve files
!insertmacro MUI_RESERVEFILE_INSTALLOPTIONS

; MUI end ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "GT-10BFxFloorBoard_Setup.exe"
InstallDir "$PROGRAMFILES\GT-10BFxFloorBoard"
InstallDirRegKey HKLM "${PRODUCT_DIR_REGKEY}" ""
ShowInstDetails show
ShowUnInstDetails show

Section "MainSection" SEC01
  SetOutPath "$INSTDIR\"
  Delete "$INSTDIR\preferences.xml"
  SetOverwrite ifnewer
  File "GT-10BFxFloorBoard.exe"
  CreateDirectory "$SMPROGRAMS\GT-10BFxFloorBoard"
  CreateShortCut "$SMPROGRAMS\GT-10BFxFloorBoard\GT-10BFxFloorBoard.lnk" "$INSTDIR\GT-10BFxFloorBoard.exe"
  CreateShortCut "$DESKTOP\GT-10BFxFloorBoard.lnk" "$INSTDIR\GT-10BFxFloorBoard.exe"
  File "mingwm10.dll"
  File "license.txt"
  File "preferences.xml.dist"
  File "GT-10BFxFloorBoard_help.html"
  SetOutPath "$INSTDIR\Init Patches"
  SetOverwrite try
  File "Init Patches\$toneBlue Chorus.syx"
  File "Init Patches\$toneBlue drive.syx"
  File "Init Patches\$toneBlue_Fuzzy.syx"
  File "Init Patches\Blank_Init_patch.syx"
  File "Init Patches\70's Jazz-Fusion.syx"
  File "Init Patches\eXPERIMENT.syx"
  File "Init Patches\GT10patch.syx"
  File "Init Patches\gt6b_patch.syx"
  File "Init Patches\mad scientist.syx"
  File "Init Patches\sequencer circus.syx"
  File "Init Patches\spacebar.syx"
  File "Init Patches\super dooper.syx"
  File "Init Patches\synthdrive venus.syx"
  File "Init Patches\ugly.syx"
  File "Init Patches\venuspedal.syx"
  SetOutPath "$INSTDIR\GT-10BFxFloorBoard_help_files"
  File "GT-10BFxFloorBoard_help_files\filelist.xml"
  File "GT-10BFxFloorBoard_help_files\image001.gif"
  File "GT-10BFxFloorBoard_help_files\image002.gif"
  File "GT-10BFxFloorBoard_help_files\image003.gif"
  File "GT-10BFxFloorBoard_help_files\image005.gif"
  File "GT-10BFxFloorBoard_help_files\image006.gif"
  File "GT-10BFxFloorBoard_help_files\image007.jpg"
  File "GT-10BFxFloorBoard_help_files\image008.gif"
  File "GT-10BFxFloorBoard_help_files\image009.jpg"
  File "GT-10BFxFloorBoard_help_files\image010.gif"
  File "GT-10BFxFloorBoard_help_files\image011.gif"
  File "GT-10BFxFloorBoard_help_files\image012.jpg"
  File "GT-10BFxFloorBoard_help_files\image013.jpg"
  File "GT-10BFxFloorBoard_help_files\image014.jpg"
  File "GT-10BFxFloorBoard_help_files\image015.jpg"
  File "GT-10BFxFloorBoard_help_files\image016.gif"
  File "GT-10BFxFloorBoard_help_files\image017.gif"
  File "GT-10BFxFloorBoard_help_files\image020.gif"
  File "GT-10BFxFloorBoard_help_files\image021.gif"
  File "GT-10BFxFloorBoard_help_files\image022.gif"
  File "GT-10BFxFloorBoard_help_files\image024.jpg"
  SetOverwrite ifnewer
  File "readme.txt"
SectionEnd

Section -AdditionalIcons
  SetOutPath $INSTDIR
  WriteIniStr "$INSTDIR\${PRODUCT_NAME}.url" "InternetShortcut" "URL" "${PRODUCT_WEB_SITE}"
  CreateShortCut "$SMPROGRAMS\GT-10BFxFloorBoard\Website.lnk" "$INSTDIR\${PRODUCT_NAME}.url"
  CreateShortCut "$SMPROGRAMS\GT-10BFxFloorBoard\Uninstall.lnk" "$INSTDIR\uninst.exe"
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\GT-10BFxFloorBoard.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon" "$INSTDIR\GT-10BFxFloorBoard.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayVersion" "${PRODUCT_VERSION}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "URLInfoAbout" "${PRODUCT_WEB_SITE}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "Publisher" "${PRODUCT_PUBLISHER}"
SectionEnd


Function un.onUninstSuccess
  HideWindow
  MessageBox MB_ICONINFORMATION|MB_OK "$(^Name) was successfully removed from your computer."
FunctionEnd

Function un.onInit
  MessageBox MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2 "Are you sure you want to completely remove $(^Name) and all of its components?" IDYES +2
  Abort
FunctionEnd

Section Uninstall
  Delete "$INSTDIR\${PRODUCT_NAME}.url"
  Delete "$INSTDIR\uninst.exe"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\readme.txt"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image024.jpg"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image022.gif"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image021.gif"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image020.gif"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image017.gif"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image016.gif"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image015.jpg"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image014.jpg"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image013.jpg"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image012.jpg"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image011.gif"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image010.gif"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image009.jpg"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image008.gif"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image007.jpg"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image006.gif"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image005.gif"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image003.gif"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image002.gif"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\image001.gif"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help_files\filelist.xml"
  Delete "$INSTDIR\Init Patches\venuspedal.syx"
  Delete "$INSTDIR\Init Patches\ugly.syx"
  Delete "$INSTDIR\Init Patches\synthdrive venus.syx"
  Delete "$INSTDIR\Init Patches\super dooper.syx"
  Delete "$INSTDIR\Init Patches\spacebar.syx"
  Delete "$INSTDIR\Init Patches\sequencer circus.syx"
  Delete "$INSTDIR\Init Patches\mad scientist.syx"
  Delete "$INSTDIR\Init Patches\gt6b_patch.syx"
  Delete "$INSTDIR\Init Patches\GT10patch.syx"
  Delete "$INSTDIR\Init Patches\eXPERIMENT.syx"
  Delete "$INSTDIR\Init Patches\70's Jazz-Fusion.syx"
  Delete "$INSTDIR\Init Patches\$$toneBlue drive.syx"
  Delete "$INSTDIR\Init Patches\$$toneBlue Chorus.syx"
  Delete "$INSTDIR\Init Patches\$$toneBlue_Fuzzy.syx"
  Delete "$INSTDIR\Init Patches\Blank_Init_patch.syx"
  Delete "$INSTDIR\GT-10BFxFloorBoard_help.html"
  Delete "$INSTDIR\license.txt"
  Delete "$INSTDIR\preferences.xml.dist"
  Delete "$INSTDIR\preferences.xml"
  Delete "$INSTDIR\mingwm10.dll"
  Delete "$INSTDIR\GT-10BFxFloorBoard.exe"

  Delete "$SMPROGRAMS\GT-10BFxFloorBoard\Uninstall.lnk"
  Delete "$SMPROGRAMS\GT-10BFxFloorBoard\Website.lnk"
  Delete "$DESKTOP\GT-10BFxFloorBoard.lnk"
  Delete "$SMPROGRAMS\GT-10BFxFloorBoard\GT-10BFxFloorBoard.lnk"

  RMDir "$SMPROGRAMS\GT-10BFxFloorBoard"
  RMDir "$INSTDIR\Init Patches"
  RMDir "$INSTDIR\GT-10BFxFloorBoard_help_files"
  RMDir "$INSTDIR\"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  SetAutoClose true
SectionEnd