; Script generated by the HM NIS Edit Script Wizard.

; HM NIS Edit Wizard helper defines
!define PRODUCT_NAME "GT-6BFxFloorBoard"
!define PRODUCT_VERSION "20080724"
!define PRODUCT_PUBLISHER "Gumtownbassman"
!define PRODUCT_WEB_SITE "http://gtx.tinfoilmusic.net/"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\gt6bfxfloorboard.exe"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"

SetCompressor lzma

; MUI 1.67 compatible ------
!include "MUI.nsh"

; MUI Settings
!define MUI_ABORTWARNING
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\orange-install-nsis.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\orange-uninstall-nsis.ico"

; Welcome page
!insertmacro MUI_PAGE_WELCOME
; License page
!insertmacro MUI_PAGE_LICENSE "license.txt"
; Directory page
!insertmacro MUI_PAGE_DIRECTORY
; Instfiles page
!insertmacro MUI_PAGE_INSTFILES
; Finish page
!define MUI_FINISHPAGE_RUN "$INSTDIR\gt6bfxfloorboard.exe"
!define MUI_FINISHPAGE_SHOWREADME "$INSTDIR\Init Patches\readme.txt"
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages
!insertmacro MUI_UNPAGE_INSTFILES

; Language files
!insertmacro MUI_LANGUAGE "English"

; Reserve files
!insertmacro MUI_RESERVEFILE_INSTALLOPTIONS

; MUI end ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "GT-6BFxFloorBoard-Setup.exe"
InstallDir "$PROGRAMFILES\GT-6BFxFloorBoard"
InstallDirRegKey HKLM "${PRODUCT_DIR_REGKEY}" ""
ShowInstDetails show
ShowUnInstDetails show

Section "MainSection" SEC01
  SetOutPath "$INSTDIR"
  SetOverwrite ifnewer
  File "gt6bfxfloorboard.exe"
  CreateDirectory "$SMPROGRAMS\GT-6BFxFloorBoard"
  CreateShortCut "$SMPROGRAMS\GT-6BFxFloorBoard\GT-6BFxFloorBoard.lnk" "$INSTDIR\gt6bfxfloorboard.exe"
  CreateShortCut "$DESKTOP\GT-6BFxFloorBoard.lnk" "$INSTDIR\gt6bfxfloorboard.exe"
  File "GT-6BEditorManual_E.htm"
  File "mingwm10.dll"
  SetOutPath "$INSTDIR\Init Patches"
  SetOverwrite try
  File "init patches\$$Moneymaker$.syx"
  File "init patches\01_Compressor.syx"
  File "init patches\01_octave on exp pedal.syx"
  File "init patches\AndSheToldMe.syx"
  File "init patches\blank.syx"
  File "init patches\DamnSynth.syx"
  File "init patches\default.syx"
  File "init patches\default2.syx"
  File "init patches\MKingStatus.syx"
  File "init patches\Moneymaker$.syx"
  File "init patches\raney Wah.syx"
  File "init patches\readme.txt"
  File "init patches\Riff Madness u9-3.syx"
  File "init patches\saved.syx"
  File "init patches\saved2.syx"
  File "init patches\SlapaModulate.syx"
  File "init patches\slapin'theTrace.syx"
  File "init patches\Synthasweep.syx"
  File "init patches\venus pedal.syx"
  File "init patches\[factory]U4-1 Closed Session.syx"
  File "init patches\[factory]U4-2 Rock Session!.syx"
  File "init patches\[factory]U4-3 Deep & Throaty.syx"
  File "init patches\[factory]U4-4 Grunge.syx"
SectionEnd

Section -AdditionalIcons
  SetOutPath $INSTDIR
  WriteIniStr "$INSTDIR\${PRODUCT_NAME}.url" "InternetShortcut" "URL" "${PRODUCT_WEB_SITE}"
  CreateShortCut "$SMPROGRAMS\GT-6BFxFloorBoard\Website.lnk" "$INSTDIR\${PRODUCT_NAME}.url"
  CreateShortCut "$SMPROGRAMS\GT-6BFxFloorBoard\Uninstall.lnk" "$INSTDIR\uninst.exe"
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\gt6bfxfloorboard.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon" "$INSTDIR\gt6bfxfloorboard.exe"
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
  Delete "$INSTDIR\Init Patches\[factory]U4-4 Grunge.syx"
  Delete "$INSTDIR\Init Patches\[factory]U4-3 Deep & Throaty.syx"
  Delete "$INSTDIR\Init Patches\[factory]U4-2 Rock Session!.syx"
  Delete "$INSTDIR\Init Patches\[factory]U4-1 Closed Session.syx"
  Delete "$INSTDIR\Init Patches\venus pedal.syx"
  Delete "$INSTDIR\Init Patches\Synthasweep.syx"
  Delete "$INSTDIR\Init Patches\slapin'theTrace.syx"
  Delete "$INSTDIR\Init Patches\SlapaModulate.syx"
  Delete "$INSTDIR\Init Patches\saved2.syx"
  Delete "$INSTDIR\Init Patches\saved.syx"
  Delete "$INSTDIR\Init Patches\Riff Madness u9-3.syx"
  Delete "$INSTDIR\Init Patches\readme.txt"
  Delete "$INSTDIR\Init Patches\raney Wah.syx"
  Delete "$INSTDIR\Init Patches\Moneymaker$$.syx"
  Delete "$INSTDIR\Init Patches\MKingStatus.syx"
  Delete "$INSTDIR\Init Patches\default2.syx"
  Delete "$INSTDIR\Init Patches\default.syx"
  Delete "$INSTDIR\Init Patches\DamnSynth.syx"
  Delete "$INSTDIR\Init Patches\blank.syx"
  Delete "$INSTDIR\Init Patches\AndSheToldMe.syx"
  Delete "$INSTDIR\Init Patches\01_octave on exp pedal.syx"
  Delete "$INSTDIR\Init Patches\01_Compressor.syx"
  Delete "$INSTDIR\Init Patches\$$$$Moneymaker$$.syx"
  Delete "$INSTDIR\mingwm10.dll"
  Delete "$INSTDIR\GT-6BEditorManual_E.htm"
  Delete "$INSTDIR\gt6bfxfloorboard.exe"

  Delete "$SMPROGRAMS\GT-6BFxFloorBoard\Uninstall.lnk"
  Delete "$SMPROGRAMS\GT-6BFxFloorBoard\Website.lnk"
  Delete "$DESKTOP\GT-6BFxFloorBoard.lnk"
  Delete "$SMPROGRAMS\GT-6BFxFloorBoard\GT-6BFxFloorBoard.lnk"

  RMDir "$SMPROGRAMS\GT-6BFxFloorBoard"
  RMDir "$INSTDIR\Init Patches"
  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  SetAutoClose true
SectionEnd