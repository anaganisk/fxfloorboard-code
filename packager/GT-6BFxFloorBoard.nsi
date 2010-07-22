; Script generated by the HM NIS Edit Script Wizard.

; HM NIS Edit Wizard helper defines
!define PRODUCT_NAME "GT-6BFxFloorBoard"
!define PRODUCT_VERSION "20100722"
!define PRODUCT_PUBLISHER "gumtown"
!define PRODUCT_WEB_SITE "http://gtx.tinfoilmusic.net"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\GT-6BFxFloorBoard.exe"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"

SetCompressor lzma

; MUI 1.67 compatible ------
!include "MUI.nsh"

; MUI Settings
!define MUI_ABORTWARNING
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\modern-install.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall.ico"

; Language Selection Dialog Settings
!define MUI_LANGDLL_REGISTRY_ROOT "${PRODUCT_UNINST_ROOT_KEY}"
!define MUI_LANGDLL_REGISTRY_KEY "${PRODUCT_UNINST_KEY}"
!define MUI_LANGDLL_REGISTRY_VALUENAME "NSIS:Language"

; Welcome page
!insertmacro MUI_PAGE_WELCOME
; License page
!insertmacro MUI_PAGE_LICENSE "license.txt"
; Directory page
!insertmacro MUI_PAGE_DIRECTORY
; Instfiles page
!insertmacro MUI_PAGE_INSTFILES
; Finish page
!define MUI_FINISHPAGE_RUN "$INSTDIR\GT-6BFxFloorBoard.exe"
!define MUI_FINISHPAGE_SHOWREADME "$INSTDIR\init patches\readme.txt"
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages
!insertmacro MUI_UNPAGE_INSTFILES

; Language files
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "French"
!insertmacro MUI_LANGUAGE "German"

; Reserve files
!insertmacro MUI_RESERVEFILE_INSTALLOPTIONS

; MUI end ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "GT-6BFxFloorBoard-Setup.exe"
InstallDir "$PROGRAMFILES\GT-6BFxFloorBoard"
InstallDirRegKey HKLM "${PRODUCT_DIR_REGKEY}" ""
ShowInstDetails show
ShowUnInstDetails show

Function .onInit
  !insertmacro MUI_LANGDLL_DISPLAY
FunctionEnd

Section "MainSection" SEC01
  SetOutPath "$INSTDIR"
  SetOverwrite ifnewer
  File "saved2.GT6B_system_syx"
  File "preferences.xml.dist"
  File "mingwm10.dll"
  File "license.txt"
  File "GT-6BFxFloorBoard.exe"
  CreateDirectory "$SMPROGRAMS\GT-6BFxFloorBoard"
  CreateShortCut "$SMPROGRAMS\GT-6BFxFloorBoard\GT-6BFxFloorBoard.lnk" "$INSTDIR\GT-6BFxFloorBoard.exe"
  CreateShortCut "$DESKTOP\GT-6BFxFloorBoard.lnk" "$INSTDIR\GT-6BFxFloorBoard.exe"
  File "GT-6BEditorManual_E.htm"
  SetOutPath "$INSTDIR\init patches"
  SetOverwrite try
  File "New folder\$$Moneymaker$.syx"
  File "New folder\01_Compressor.syx"
  File "New folder\01_octave on exp pedal.syx"
  File "New folder\AndSheToldMe.syx"
  File "New folder\ARSession01.syx"
  File "New folder\ARSession02.syx"
  File "New folder\ARSession03.syx"
  File "New folder\ARSession04.syx"
  File "New folder\ARSession05.syx"
  File "New folder\blank.syx"
  File "New folder\ByPass.syx"
  File "New folder\CewlFaze.syx"
  File "New folder\Clean.syx"
  File "New folder\DamnSynth.syx"
  File "New folder\default.syx"
  File "New folder\default2.syx"
  File "New folder\EQJaco~.syx"
  File "New folder\EQMiller.syx"
  File "New folder\EQReggae.syx"
  File "New folder\EQRhythem.syx"
  File "New folder\EQRockBass.syx"
  File "New folder\InYourFace.syx"
  File "New folder\Main Frame.syx"
  File "New folder\MillerTime.syx"
  File "New folder\MKingEssential.syx"
  File "New folder\MKingJayDee.syx"
  File "New folder\MKingStatus.syx"
  File "New folder\Moneymaker$.syx"
  File "New folder\Nirvana-Come-As-You-Are.syx"
  File "New folder\Patch Select.syx"
  File "New folder\Pitch Double.syx"
  File "New folder\raney Wah.syx"
  File "New folder\readme.txt"
  File "New folder\Riff Madness u9-3.syx"
  File "New folder\saved.syx"
  File "New folder\saved2.syx"
  File "New folder\SBSlap.syx"
  File "New folder\SlapaModulate.syx"
  File "New folder\slapin'theTrace.syx"
  File "New folder\Sledgehammer.syx"
  File "New folder\Synthasweep.syx"
  File "New folder\Tool-IbanezSR806-LaneyRichter400.syx"
  File "New folder\Twang.syx"
  File "New folder\Twang2.syx"
  File "New folder\venus pedal.syx"
  File "New folder\[factory]U4-1 Closed Session.syx"
  File "New folder\[factory]U4-2 Rock Session!.syx"
  File "New folder\[factory]U4-3 Deep & Throaty.syx"
  File "New folder\[factory]U4-4 Grunge.syx"
  SetOverwrite ifnewer
  File "readme.txt"
SectionEnd

Section -AdditionalIcons
  SetOutPath $INSTDIR
  WriteIniStr "$INSTDIR\${PRODUCT_NAME}.url" "InternetShortcut" "URL" "${PRODUCT_WEB_SITE}"
  CreateShortCut "$SMPROGRAMS\GT-6BFxFloorBoard\Website.lnk" "$INSTDIR\${PRODUCT_NAME}.url"
  CreateShortCut "$SMPROGRAMS\GT-6BFxFloorBoard\Uninstall.lnk" "$INSTDIR\uninst.exe"
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\GT-6BFxFloorBoard.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon" "$INSTDIR\GT-6BFxFloorBoard.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayVersion" "${PRODUCT_VERSION}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "URLInfoAbout" "${PRODUCT_WEB_SITE}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "Publisher" "${PRODUCT_PUBLISHER}"
SectionEnd


Function un.onUninstSuccess
  HideWindow
  MessageBox MB_ICONINFORMATION|MB_OK "$(^Name) was successfully removed from your computer."
FunctionEnd

Function un.onInit
!insertmacro MUI_UNGETLANGUAGE
  MessageBox MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2 "Are you sure you want to completely remove $(^Name) and all of its components?" IDYES +2
  Abort
FunctionEnd

Section Uninstall
  Delete "$INSTDIR\${PRODUCT_NAME}.url"
  Delete "$INSTDIR\uninst.exe"
  Delete "$INSTDIR\init patches\readme.txt"
  Delete "$INSTDIR\init patches\[factory]U4-4 Grunge.syx"
  Delete "$INSTDIR\init patches\[factory]U4-3 Deep & Throaty.syx"
  Delete "$INSTDIR\init patches\[factory]U4-2 Rock Session!.syx"
  Delete "$INSTDIR\init patches\[factory]U4-1 Closed Session.syx"
  Delete "$INSTDIR\init patches\venus pedal.syx"
  Delete "$INSTDIR\init patches\Twang2.syx"
  Delete "$INSTDIR\init patches\Twang.syx"
  Delete "$INSTDIR\init patches\Tool-IbanezSR806-LaneyRichter400.syx"
  Delete "$INSTDIR\init patches\Synthasweep.syx"
  Delete "$INSTDIR\init patches\Sledgehammer.syx"
  Delete "$INSTDIR\init patches\slapin'theTrace.syx"
  Delete "$INSTDIR\init patches\SlapaModulate.syx"
  Delete "$INSTDIR\init patches\SBSlap.syx"
  Delete "$INSTDIR\init patches\saved2.syx"
  Delete "$INSTDIR\init patches\saved.syx"
  Delete "$INSTDIR\init patches\Riff Madness u9-3.syx"
  Delete "$INSTDIR\init patches\readme.txt"
  Delete "$INSTDIR\init patches\raney Wah.syx"
  Delete "$INSTDIR\init patches\Pitch Double.syx"
  Delete "$INSTDIR\init patches\Patch Select.syx"
  Delete "$INSTDIR\init patches\Nirvana-Come-As-You-Are.syx"
  Delete "$INSTDIR\init patches\Moneymaker$$.syx"
  Delete "$INSTDIR\init patches\MKingStatus.syx"
  Delete "$INSTDIR\init patches\MKingJayDee.syx"
  Delete "$INSTDIR\init patches\MKingEssential.syx"
  Delete "$INSTDIR\init patches\MillerTime.syx"
  Delete "$INSTDIR\init patches\Main Frame.syx"
  Delete "$INSTDIR\init patches\InYourFace.syx"
  Delete "$INSTDIR\init patches\EQRockBass.syx"
  Delete "$INSTDIR\init patches\EQRhythem.syx"
  Delete "$INSTDIR\init patches\EQReggae.syx"
  Delete "$INSTDIR\init patches\EQMiller.syx"
  Delete "$INSTDIR\init patches\EQJaco~.syx"
  Delete "$INSTDIR\init patches\default2.syx"
  Delete "$INSTDIR\init patches\default.syx"
  Delete "$INSTDIR\init patches\DamnSynth.syx"
  Delete "$INSTDIR\init patches\Clean.syx"
  Delete "$INSTDIR\init patches\CewlFaze.syx"
  Delete "$INSTDIR\init patches\ByPass.syx"
  Delete "$INSTDIR\init patches\blank.syx"
  Delete "$INSTDIR\init patches\ARSession05.syx"
  Delete "$INSTDIR\init patches\ARSession04.syx"
  Delete "$INSTDIR\init patches\ARSession03.syx"
  Delete "$INSTDIR\init patches\ARSession02.syx"
  Delete "$INSTDIR\init patches\ARSession01.syx"
  Delete "$INSTDIR\init patches\AndSheToldMe.syx"
  Delete "$INSTDIR\init patches\01_octave on exp pedal.syx"
  Delete "$INSTDIR\init patches\01_Compressor.syx"
  Delete "$INSTDIR\init patches\$$$$Moneymaker$$.syx"
  Delete "$INSTDIR\GT-6BEditorManual_E.htm"
  Delete "$INSTDIR\GT-6BFxFloorBoard.exe"
  Delete "$INSTDIR\license.txt"
  Delete "$INSTDIR\mingwm10.dll"
  Delete "$INSTDIR\preferences.xml.dist"
  Delete "$INSTDIR\saved2.GT6B_system_syx"

  Delete "$SMPROGRAMS\GT-6BFxFloorBoard\Uninstall.lnk"
  Delete "$SMPROGRAMS\GT-6BFxFloorBoard\Website.lnk"
  Delete "$DESKTOP\GT-6BFxFloorBoard.lnk"
  Delete "$SMPROGRAMS\GT-6BFxFloorBoard\GT-6BFxFloorBoard.lnk"

  RMDir "$SMPROGRAMS\GT-6BFxFloorBoard"
  RMDir "$INSTDIR\init patches"
  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  SetAutoClose true
SectionEnd