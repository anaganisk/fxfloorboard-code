; Script generated by the HM NIS Edit Script Wizard.

; HM NIS Edit Wizard helper defines
!define PRODUCT_NAME "GT-8FxFloorBoard"
!define PRODUCT_VERSION "20090522"
!define PRODUCT_PUBLISHER "gumtownbassman"
!define PRODUCT_WEB_SITE "http://gtx.tinfoilmusic.net"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\GT-8FxFloorBoard.exe"
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
!define MUI_FINISHPAGE_RUN "$INSTDIR\GT-8FxFloorBoard.exe"
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
OutFile "GT-8FxFloorBoard-Setup.exe"
InstallDir "$PROGRAMFILES\GT-8FxFloorBoard"
InstallDirRegKey HKLM "${PRODUCT_DIR_REGKEY}" ""
ShowInstDetails show
ShowUnInstDetails show

Section "MainSection" SEC01
  SetOutPath "$INSTDIR"
  SetOverwrite ifnewer
  File "GT-8FxFloorBoard.exe"
  CreateDirectory "$SMPROGRAMS\GT-8FxFloorBoard"
  CreateShortCut "$SMPROGRAMS\GT-8FxFloorBoard\GT-8FxFloorBoard.lnk" "$INSTDIR\GT-8FxFloorBoard.exe"
  CreateShortCut "$DESKTOP\GT-8FxFloorBoard.lnk" "$INSTDIR\GT-8FxFloorBoard.exe"
  File "GT-8EditorManual_E.htm"
  File "mingwm10.dll"
  File "license.txt"
  File "preferences.xml.dist"
  SetOutPath "$INSTDIR\Init Patches"
  SetOverwrite try
  File "Init Patches\000_INIT_Empty.syx"
  File "Init Patches\001_INIT_(JC_Clean)_Roland_JC120.syx"
  File "Init Patches\002_INIT_(JC_Clean)_Warm_Clean.syx"
  File "Init Patches\003_INIT_(JC_Clean)_Polytone_Mini_Brute_Jazz_Combo.syx"
  File "Init Patches\004_INIT_(JC_Clean)_Full_Range.syx"
  File "Init Patches\005_INIT_(JC_Clean)_Bright_Clean.syx"
  File "Init Patches\006_INIT_(TW_Clean)_Fender_Twin_Reverb_Clean.syx"
  File "Init Patches\007_INIT_(TW_Clean)_Fender_Pro_Reverb_Crunch.syx"
  File "Init Patches\008_INIT_(TW_Clean)_Fender_Bassman_Tweed.syx"
  File "Init Patches\009_INIT_(TW_Clean)_Warm_Crunch.syx"
  File "Init Patches\010_INIT_(Chrunch)_Crunch.syx"
  File "Init Patches\011_INIT_(Chrunch)_Fender_Blues_Deville.syx"
  File "Init Patches\012_INIT_(Chrunch)_Hiwatt_Bright_Channel_Wild_Crunch.syx"
  File "Init Patches\013_INIT_(Chrunch)_Marshall_JTM-45_Stack_Crunch.syx"
  File "Init Patches\014_INIT_(Combo)_Vox_AC-30TB_Drive.syx"
  File "Init Patches\015_INIT_(Combo)_Vox_AC-30TB_Lead.syx"
  File "Init Patches\016_INIT_(Combo)_Vox_AC-30TB_Clean.syx"
  File "Init Patches\017_INIT_(Combo)_Matchless_D-!-C-30_Drive.syx"
  File "Init Patches\018_INIT_(Combo)_Matchless_D-!-C-30_Hi Gain_Fat_Drive.syx"
  File "Init Patches\019_INIT_(Combo)_Matchless_D-!-C-30_Right_Lead.syx"
  File "Init Patches\020_INIT_(BG_Lead)_Messa_Boogie_Lead.syx"
  File "Init Patches\021_INIT_(BG_Lead)_Messa_Boogie_Trebble_Drive.syx"
  File "Init Patches\022_INIT_(BG_Lead)_Messa_Boogie_Rhythm.syx"
  File "Init Patches\023_INIT_(BG_Lead)_Messa_Boogie_Mark_I_Smooth_Drive.syx"
  File "Init Patches\024_INIT_(BG_Lead)_Messa_Boogie_Mark_II_Mild_Drive.syx"
  File "Init Patches\025_INIT_(MS_Stack)_Marshall_1959_input_I.syx"
  File "Init Patches\026_INIT_(MS_Stack)_Marshall_1959_input_II.syx"
  File "Init Patches\027_INIT_(MS_Stack)_Marshall_1959_parallel_I+II.syx"
  File "Init Patches\028_INIT_(MS_Stack)_Marshall_JCM-800_HiGain.syx"
  File "Init Patches\029_INIT_(MS_Stack)_Marshall_JCM_Silver_Jubilee_Power_Stack.syx"
  File "Init Patches\030_INIT_(R-Fier)_Messa_Boogie_Dual_Rectifier_clean.syx"
  File "Init Patches\031_INIT_(R-Fier)_Messa_Boogie_Dual_Rectifier_raw.syx"
  File "Init Patches\032_INIT_(R-Fier)_Messa_Boogie_Dual_Rectifier_vintage_chn._1.syx"
  File "Init Patches\033_INIT_(R-Fier)_Messa_Boogie_Dual_Rectifier_modern_chn._1.syx"
  File "Init Patches\034_INIT_(R-Fier)_Messa_Boogie_Dual_Rectifier_vintage_chn._2.syx"
  File "Init Patches\035_INIT_(R-Fier)_Messa_Boogie_Dual_Rectifier_modern_chn._2.syx"
  File "Init Patches\036_INIT_(T-Amp)_Hughes_&_Kettner_Triamp_Clean.syx"
  File "Init Patches\037_INIT_(T-Amp)_Hughes_&_Kettner_Triamp_Crunch.syx"
  File "Init Patches\038_INIT_(T-Amp)_Hughes_&_Kettner_Triamp_Lead.syx"
  File "Init Patches\039_INIT_(T-Amp)_Edge_Lead.syx"
  File "Init Patches\040_INIT_(HiGain)_Soldano_SLO-100.syx"
  File "Init Patches\041_INIT_(HiGain)_Drive_Stack.syx"
  File "Init Patches\042_INIT_(HiGain)_Lead_Stack.syx"
  File "Init Patches\043_INIT_(HiGain)_Heavy_Lead.syx"
  File "Init Patches\044_INIT_(Metal)_Peavey EVH_5150.syx"
  File "Init Patches\045_INIT_(Metal)_Messa_Boogie_Tripple_Rectifier_Metal_Stack.syx"
  File "Init Patches\046_INIT_(Metal)_Metal_Lead.syx"
  File "Init Patches\047_INIT_(Custom)_Custom_1.syx"
  File "Init Patches\047_INIT_(Custom)_Custom_2.syx"
  File "Init Patches\049_INIT_(Custom)_Custom_3.syx"
  File "Init Patches\readme.txt"
SectionEnd

Section -AdditionalIcons
  SetOutPath $INSTDIR
  WriteIniStr "$INSTDIR\${PRODUCT_NAME}.url" "InternetShortcut" "URL" "${PRODUCT_WEB_SITE}"
  CreateShortCut "$SMPROGRAMS\GT-8FxFloorBoard\Website.lnk" "$INSTDIR\${PRODUCT_NAME}.url"
  CreateShortCut "$SMPROGRAMS\GT-8FxFloorBoard\Uninstall.lnk" "$INSTDIR\uninst.exe"
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\GT-8FxFloorBoard.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon" "$INSTDIR\GT-8FxFloorBoard.exe"
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
  Delete "$INSTDIR\Init Patches\readme.txt"
  Delete "$INSTDIR\Init Patches\049_INIT_(Custom)_Custom_3.syx"
  Delete "$INSTDIR\Init Patches\047_INIT_(Custom)_Custom_2.syx"
  Delete "$INSTDIR\Init Patches\047_INIT_(Custom)_Custom_1.syx"
  Delete "$INSTDIR\Init Patches\046_INIT_(Metal)_Metal_Lead.syx"
  Delete "$INSTDIR\Init Patches\045_INIT_(Metal)_Messa_Boogie_Tripple_Rectifier_Metal_Stack.syx"
  Delete "$INSTDIR\Init Patches\044_INIT_(Metal)_Peavey EVH_5150.syx"
  Delete "$INSTDIR\Init Patches\043_INIT_(HiGain)_Heavy_Lead.syx"
  Delete "$INSTDIR\Init Patches\042_INIT_(HiGain)_Lead_Stack.syx"
  Delete "$INSTDIR\Init Patches\041_INIT_(HiGain)_Drive_Stack.syx"
  Delete "$INSTDIR\Init Patches\040_INIT_(HiGain)_Soldano_SLO-100.syx"
  Delete "$INSTDIR\Init Patches\039_INIT_(T-Amp)_Edge_Lead.syx"
  Delete "$INSTDIR\Init Patches\038_INIT_(T-Amp)_Hughes_&_Kettner_Triamp_Lead.syx"
  Delete "$INSTDIR\Init Patches\037_INIT_(T-Amp)_Hughes_&_Kettner_Triamp_Crunch.syx"
  Delete "$INSTDIR\Init Patches\036_INIT_(T-Amp)_Hughes_&_Kettner_Triamp_Clean.syx"
  Delete "$INSTDIR\Init Patches\035_INIT_(R-Fier)_Messa_Boogie_Dual_Rectifier_modern_chn._2.syx"
  Delete "$INSTDIR\Init Patches\034_INIT_(R-Fier)_Messa_Boogie_Dual_Rectifier_vintage_chn._2.syx"
  Delete "$INSTDIR\Init Patches\033_INIT_(R-Fier)_Messa_Boogie_Dual_Rectifier_modern_chn._1.syx"
  Delete "$INSTDIR\Init Patches\032_INIT_(R-Fier)_Messa_Boogie_Dual_Rectifier_vintage_chn._1.syx"
  Delete "$INSTDIR\Init Patches\031_INIT_(R-Fier)_Messa_Boogie_Dual_Rectifier_raw.syx"
  Delete "$INSTDIR\Init Patches\030_INIT_(R-Fier)_Messa_Boogie_Dual_Rectifier_clean.syx"
  Delete "$INSTDIR\Init Patches\029_INIT_(MS_Stack)_Marshall_JCM_Silver_Jubilee_Power_Stack.syx"
  Delete "$INSTDIR\Init Patches\028_INIT_(MS_Stack)_Marshall_JCM-800_HiGain.syx"
  Delete "$INSTDIR\Init Patches\027_INIT_(MS_Stack)_Marshall_1959_parallel_I+II.syx"
  Delete "$INSTDIR\Init Patches\026_INIT_(MS_Stack)_Marshall_1959_input_II.syx"
  Delete "$INSTDIR\Init Patches\025_INIT_(MS_Stack)_Marshall_1959_input_I.syx"
  Delete "$INSTDIR\Init Patches\024_INIT_(BG_Lead)_Messa_Boogie_Mark_II_Mild_Drive.syx"
  Delete "$INSTDIR\Init Patches\023_INIT_(BG_Lead)_Messa_Boogie_Mark_I_Smooth_Drive.syx"
  Delete "$INSTDIR\Init Patches\022_INIT_(BG_Lead)_Messa_Boogie_Rhythm.syx"
  Delete "$INSTDIR\Init Patches\021_INIT_(BG_Lead)_Messa_Boogie_Trebble_Drive.syx"
  Delete "$INSTDIR\Init Patches\020_INIT_(BG_Lead)_Messa_Boogie_Lead.syx"
  Delete "$INSTDIR\Init Patches\019_INIT_(Combo)_Matchless_D-!-C-30_Right_Lead.syx"
  Delete "$INSTDIR\Init Patches\018_INIT_(Combo)_Matchless_D-!-C-30_Hi Gain_Fat_Drive.syx"
  Delete "$INSTDIR\Init Patches\017_INIT_(Combo)_Matchless_D-!-C-30_Drive.syx"
  Delete "$INSTDIR\Init Patches\016_INIT_(Combo)_Vox_AC-30TB_Clean.syx"
  Delete "$INSTDIR\Init Patches\015_INIT_(Combo)_Vox_AC-30TB_Lead.syx"
  Delete "$INSTDIR\Init Patches\014_INIT_(Combo)_Vox_AC-30TB_Drive.syx"
  Delete "$INSTDIR\Init Patches\013_INIT_(Chrunch)_Marshall_JTM-45_Stack_Crunch.syx"
  Delete "$INSTDIR\Init Patches\012_INIT_(Chrunch)_Hiwatt_Bright_Channel_Wild_Crunch.syx"
  Delete "$INSTDIR\Init Patches\011_INIT_(Chrunch)_Fender_Blues_Deville.syx"
  Delete "$INSTDIR\Init Patches\010_INIT_(Chrunch)_Crunch.syx"
  Delete "$INSTDIR\Init Patches\009_INIT_(TW_Clean)_Warm_Crunch.syx"
  Delete "$INSTDIR\Init Patches\008_INIT_(TW_Clean)_Fender_Bassman_Tweed.syx"
  Delete "$INSTDIR\Init Patches\007_INIT_(TW_Clean)_Fender_Pro_Reverb_Crunch.syx"
  Delete "$INSTDIR\Init Patches\006_INIT_(TW_Clean)_Fender_Twin_Reverb_Clean.syx"
  Delete "$INSTDIR\Init Patches\005_INIT_(JC_Clean)_Bright_Clean.syx"
  Delete "$INSTDIR\Init Patches\004_INIT_(JC_Clean)_Full_Range.syx"
  Delete "$INSTDIR\Init Patches\003_INIT_(JC_Clean)_Polytone_Mini_Brute_Jazz_Combo.syx"
  Delete "$INSTDIR\Init Patches\002_INIT_(JC_Clean)_Warm_Clean.syx"
  Delete "$INSTDIR\Init Patches\001_INIT_(JC_Clean)_Roland_JC120.syx"
  Delete "$INSTDIR\Init Patches\000_INIT_Empty.syx"
  Delete "$INSTDIR\license.txt"
  Delete "$INSTDIR\mingwm10.dll"
  Delete "$INSTDIR\preferences.xml.dist"
  Delete "$INSTDIR\preferences.xml"
  Delete "$INSTDIR\GT-8EditorManual_E.htm"
  Delete "$INSTDIR\GT-8FxFloorBoard.exe"

  Delete "$SMPROGRAMS\GT-8FxFloorBoard\Uninstall.lnk"
  Delete "$SMPROGRAMS\GT-8FxFloorBoard\Website.lnk"
  Delete "$DESKTOP\GT-8FxFloorBoard.lnk"
  Delete "$SMPROGRAMS\GT-8FxFloorBoard\GT-8FxFloorBoard.lnk"

  RMDir "$SMPROGRAMS\GT-8FxFloorBoard"
  RMDir "$INSTDIR\Init Patches"
  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  SetAutoClose true
SectionEnd