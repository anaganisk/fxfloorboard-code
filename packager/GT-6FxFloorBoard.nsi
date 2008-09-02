; Script generated by the HM NIS Edit Script Wizard.

; HM NIS Edit Wizard helper defines
!define PRODUCT_NAME "GT-6FxFloorBoard"
!define PRODUCT_VERSION "beta 20080901"
!define PRODUCT_PUBLISHER "gumtownbassman"
!define PRODUCT_WEB_SITE "http://gtx.tinfoilmusic.net"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\gt6fxfloorboard.exe"
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
!define MUI_FINISHPAGE_RUN "$INSTDIR\gt6fxfloorboard.exe"
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages
!insertmacro MUI_UNPAGE_INSTFILES

; Language files
!insertmacro MUI_LANGUAGE "English"

; Reserve files
!insertmacro MUI_RESERVEFILE_INSTALLOPTIONS

; MUI end ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "GT-6FxFloorBoard-Setup.exe"
InstallDir "$PROGRAMFILES\GT-6FxFloorBoard"
InstallDirRegKey HKLM "${PRODUCT_DIR_REGKEY}" ""
ShowInstDetails show
ShowUnInstDetails show

Section "MainSection" SEC01
  SetOutPath "$INSTDIR"
  SetOverwrite ifnewer
  File "GT-6EditorManual_E.htm"
  File "gt6fxfloorboard.exe"
  CreateDirectory "$SMPROGRAMS\GT-6FxFloorBoard"
  CreateShortCut "$SMPROGRAMS\GT-6FxFloorBoard\GT-6FxFloorBoard.lnk" "$INSTDIR\gt6fxfloorboard.exe"
  CreateShortCut "$DESKTOP\GT-6FxFloorBoard.lnk" "$INSTDIR\gt6fxfloorboard.exe"
  File "mingwm10.dll"
  File "preferences.xml.dist"
  SetOutPath "$INSTDIR\init patches"
  SetOverwrite try
  File "init patches\acdcblack17-3.syx"
  File "init patches\Blue Chorus.syx"
  File "init patches\Blue Hotel.syx"
  File "init patches\BluesDrive.syx"
  File "init patches\Cho CRUNCH.syx"
  File "init patches\Crowded house.syx"
  File "init patches\detroit.syx"
  File "init patches\dire2.syx"
  File "init patches\direstraits.syx"
  File "init patches\disco.syx"
  File "init patches\Dissection.syx"
  File "init patches\drivesolo.syx"
  File "init patches\ericclapton17-2.syx"
  File "init patches\Gimme some lovin.syx"
  File "init patches\GNR_Dont_Cry.syx"
  File "init patches\GNR_N_ON_HD.syx"
  File "init patches\GT-crunch.syx"
  File "init patches\In Flames.syx"
  File "init patches\Karelia Blue.syx"
  File "init patches\Karelia.syx"
  File "init patches\lametal.syx"
  File "init patches\marillionsolo29-2.syx"
  File "init patches\mesa.syx"
  File "init patches\Mysterious Ways.syx"
  File "init patches\Opeth.syx"
  File "init patches\pink floyd another 1.syx"
  File "init patches\pink floyd brick part 3.syx"
  File "init patches\pink floyd brick solo.syx"
  File "init patches\pink floyd brick verse.syx"
  File "init patches\pink floyd clean wall.syx"
  File "init patches\pink floyd comfortably numb chorus.syx"
  File "init patches\pink floyd comfortably numb verse.syx"
  File "init patches\pink floyd comfortably numb.syx"
  File "init patches\pink floyd keep talking 2.syx"
  File "init patches\pink floyd keep talking 3.syx"
  File "init patches\pink floyd keep talking.syx"
  File "init patches\pink floyd learning to fly.syx"
  File "init patches\pink floyd marooned.syx"
  File "init patches\pink floyd money.syx"
  File "init patches\pink floyd.syx"
  File "init patches\Queen-AC30.syx"
  File "init patches\Queen-Brian echo.syx"
  File "init patches\Queen-Brian May.syx"
  File "init patches\Queen-gat.syx"
  File "init patches\Satriani-low vox.syx"
  File "init patches\Satriani-Marshall low.syx"
  File "init patches\Satriani-Marshall tremolo.syx"
  File "init patches\Satriani-MS Highgain high.syx"
  File "init patches\Satriani-tremolo marshall 2.syx"
  File "init patches\Satriani-tremolo marshall.syx"
  File "init patches\zakkwylde6-2.syx"
  File "init patches\zz-top-crunchy.syx"
  File "init patches\zz-top-dirty.syx"
  SetOutPath "$INSTDIR\GT-6EditorManual_E_files"
  File "GT-6EditorManual_E_files\filelist.xml"
  File "GT-6EditorManual_E_files\image001.jpg"
  File "GT-6EditorManual_E_files\image002.jpg"
  File "GT-6EditorManual_E_files\image003.jpg"
  File "GT-6EditorManual_E_files\image004.jpg"
  File "GT-6EditorManual_E_files\image005.jpg"
  File "GT-6EditorManual_E_files\image006.jpg"
  File "GT-6EditorManual_E_files\image007.jpg"
  File "GT-6EditorManual_E_files\image008.jpg"
  File "GT-6EditorManual_E_files\image009.jpg"
  File "GT-6EditorManual_E_files\image010.jpg"
  File "GT-6EditorManual_E_files\image011.jpg"
  File "GT-6EditorManual_E_files\image012.jpg"
  File "GT-6EditorManual_E_files\image013.jpg"
  File "GT-6EditorManual_E_files\image014.jpg"
  File "GT-6EditorManual_E_files\image015.jpg"
  File "GT-6EditorManual_E_files\image016.jpg"
  File "GT-6EditorManual_E_files\image017.jpg"
  File "GT-6EditorManual_E_files\image018.jpg"
  File "GT-6EditorManual_E_files\image019.jpg"
  File "GT-6EditorManual_E_files\image020.jpg"
  File "GT-6EditorManual_E_files\image021.jpg"
  File "GT-6EditorManual_E_files\image022.jpg"
  File "GT-6EditorManual_E_files\image023.jpg"
  File "GT-6EditorManual_E_files\image024.jpg"
  File "GT-6EditorManual_E_files\image025.jpg"
  File "GT-6EditorManual_E_files\image026.jpg"
  File "GT-6EditorManual_E_files\Thumbs.db"
SectionEnd

Section -AdditionalIcons
  SetOutPath $INSTDIR
  WriteIniStr "$INSTDIR\${PRODUCT_NAME}.url" "InternetShortcut" "URL" "${PRODUCT_WEB_SITE}"
  CreateShortCut "$SMPROGRAMS\GT-6FxFloorBoard\Website.lnk" "$INSTDIR\${PRODUCT_NAME}.url"
  CreateShortCut "$SMPROGRAMS\GT-6FxFloorBoard\Uninstall.lnk" "$INSTDIR\uninst.exe"
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\gt6fxfloorboard.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon" "$INSTDIR\gt6fxfloorboard.exe"
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
  Delete "$INSTDIR\GT-6EditorManual_E_files\Thumbs.db"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image026.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image025.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image024.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image023.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image022.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image021.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image020.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image019.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image018.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image017.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image016.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image015.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image014.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image013.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image012.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image011.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image010.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image009.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image008.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image007.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image006.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image005.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image004.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image003.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image002.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\image001.jpg"
  Delete "$INSTDIR\GT-6EditorManual_E_files\filelist.xml"
  Delete "$INSTDIR\init patches\zz-top-dirty.syx"
  Delete "$INSTDIR\init patches\zz-top-crunchy.syx"
  Delete "$INSTDIR\init patches\zakkwylde6-2.syx"
  Delete "$INSTDIR\init patches\Satriani-tremolo marshall.syx"
  Delete "$INSTDIR\init patches\Satriani-tremolo marshall 2.syx"
  Delete "$INSTDIR\init patches\Satriani-MS Highgain high.syx"
  Delete "$INSTDIR\init patches\Satriani-Marshall tremolo.syx"
  Delete "$INSTDIR\init patches\Satriani-Marshall low.syx"
  Delete "$INSTDIR\init patches\Satriani-low vox.syx"
  Delete "$INSTDIR\init patches\Queen-gat.syx"
  Delete "$INSTDIR\init patches\Queen-Brian May.syx"
  Delete "$INSTDIR\init patches\Queen-Brian echo.syx"
  Delete "$INSTDIR\init patches\Queen-AC30.syx"
  Delete "$INSTDIR\init patches\pink floyd.syx"
  Delete "$INSTDIR\init patches\pink floyd money.syx"
  Delete "$INSTDIR\init patches\pink floyd marooned.syx"
  Delete "$INSTDIR\init patches\pink floyd learning to fly.syx"
  Delete "$INSTDIR\init patches\pink floyd keep talking.syx"
  Delete "$INSTDIR\init patches\pink floyd keep talking 3.syx"
  Delete "$INSTDIR\init patches\pink floyd keep talking 2.syx"
  Delete "$INSTDIR\init patches\pink floyd comfortably numb.syx"
  Delete "$INSTDIR\init patches\pink floyd comfortably numb verse.syx"
  Delete "$INSTDIR\init patches\pink floyd comfortably numb chorus.syx"
  Delete "$INSTDIR\init patches\pink floyd clean wall.syx"
  Delete "$INSTDIR\init patches\pink floyd brick verse.syx"
  Delete "$INSTDIR\init patches\pink floyd brick solo.syx"
  Delete "$INSTDIR\init patches\pink floyd brick part 3.syx"
  Delete "$INSTDIR\init patches\pink floyd another 1.syx"
  Delete "$INSTDIR\init patches\Opeth.syx"
  Delete "$INSTDIR\init patches\Mysterious Ways.syx"
  Delete "$INSTDIR\init patches\mesa.syx"
  Delete "$INSTDIR\init patches\marillionsolo29-2.syx"
  Delete "$INSTDIR\init patches\lametal.syx"
  Delete "$INSTDIR\init patches\Karelia.syx"
  Delete "$INSTDIR\init patches\Karelia Blue.syx"
  Delete "$INSTDIR\init patches\In Flames.syx"
  Delete "$INSTDIR\init patches\GT-crunch.syx"
  Delete "$INSTDIR\init patches\GNR_N_ON_HD.syx"
  Delete "$INSTDIR\init patches\GNR_Dont_Cry.syx"
  Delete "$INSTDIR\init patches\Gimme some lovin.syx"
  Delete "$INSTDIR\init patches\ericclapton17-2.syx"
  Delete "$INSTDIR\init patches\drivesolo.syx"
  Delete "$INSTDIR\init patches\Dissection.syx"
  Delete "$INSTDIR\init patches\disco.syx"
  Delete "$INSTDIR\init patches\direstraits.syx"
  Delete "$INSTDIR\init patches\dire2.syx"
  Delete "$INSTDIR\init patches\detroit.syx"
  Delete "$INSTDIR\init patches\Crowded house.syx"
  Delete "$INSTDIR\init patches\Cho CRUNCH.syx"
  Delete "$INSTDIR\init patches\BluesDrive.syx"
  Delete "$INSTDIR\init patches\Blue Hotel.syx"
  Delete "$INSTDIR\init patches\Blue Chorus.syx"
  Delete "$INSTDIR\init patches\acdcblack17-3.syx"
  Delete "$INSTDIR\mingwm10.dll"
  Delete "$INSTDIR\gt6fxfloorboard.exe"
  Delete "$INSTDIR\GT-6EditorManual_E.htm"
  Delete "$INSTDIR\preferences.xml.dist"
  Delete "$INSTDIR\preferences.xml"

  Delete "$SMPROGRAMS\GT-6FxFloorBoard\Uninstall.lnk"
  Delete "$SMPROGRAMS\GT-6FxFloorBoard\Website.lnk"
  Delete "$DESKTOP\GT-6FxFloorBoard.lnk"
  Delete "$SMPROGRAMS\GT-6FxFloorBoard\GT-6FxFloorBoard.lnk"

  RMDir "$SMPROGRAMS\GT-6FxFloorBoard"
  RMDir "$INSTDIR\init patches"
  RMDir "$INSTDIR\GT-6EditorManual_E_files"
  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  SetAutoClose true
SectionEnd