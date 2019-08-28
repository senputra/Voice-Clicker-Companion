!include "MUI2.nsh"
!define MUI_ICON "C:\Users\dodys\source\repos\SuaraClicker\QtGuiApplication2\icon1.ico"
!define MUI_PAGE_HEADER_TEXT "Voice Clicker"
!define MUI_INSTFILESPAGE_FINISHHEADER_SUBTEXT "Installation Finished!"
!insertmacro MUI_LANGUAGE "English"
!addplugindir "C:\Program Files (x86)\NSIS\Plugins\NSIS_Simple_Firewall_Plugin_1.20\"

!define Name "Voice Clicker" # Name of the installer. 
Name "${Name}"
;  This constant specifies the installer file name.
!define InstFile "Voice Clicker Setup.exe"
OutFile "${InstFile}"
!define UinstFile "Uninstaller.exe"


# define the directory to install to, the desktop in this case as specified  
# by the predefined $DESKTOP variable
InstallDir '$PROGRAMFILES\Voice Clicker'

 
# default section
Section
# define the output path for this file
SetOutPath $INSTDIR
 
# define what to install and place it in the output path
File /r ".\installation files\*"
 
 # define uninstaller name
WriteUninstaller $INSTDIR\${UinstFile}


### REGISTRY STUFF ALL HERE
WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Name}" \
                 "DisplayName" "${Name}"

WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Name}" \
                 "DisplayIcon" "$PROGRAMFILES\Voice Clicker\Voice Clicker PC.exe"

WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Name}" \
                 "UninstallString" "$\"$INSTDIR\${UinstFile}$\""

ExecWait '$INSTDIR\dependencies\vcredist_x86.exe /passive /norestart'
ExecWait '$INSTDIR\dependencies\BonjourSetup.exe /qn'

SimpleFC::AdvRemoveRule "Voice Clicker PC"
SimpleFC::AdvAddRule "Voice Clicker PC" "Voice Clicker UDP Streams" "256" "1" \
  "1" "2147483647" "1" "$PROGRAMFILES\Voice Clicker\Voice Clicker PC.exe" "" "" \
  "" "" "" "" "" 

; "SimpleFC::AdvAddRule [name] [description] [protocol] [direction] 
;   [status] [profile] [action] [application] [service_name] [icmp_types_and_codes] 
;   [group] [local_ports] [remote_ports] [local_address] [remote_address]"
; SimpleFC::AddApplication "Voice Clicker PC.exe" "$PROGRAMFILES\Voice Clicker\Voice Clicker PC.exe" 0 2 "" 1

CreateShortcut "$desktop\Voice Clicker PC.lnk" "$instdir\Voice Clicker PC.exe" "" "$instdir\Voice Clicker PC.exe"
## Creating a directory in start menu AND a linker file.
CreateDirectory "$SMPROGRAMS\${Name}\"
CreateShortcut "$SMPROGRAMS\${Name}\Voice Clicker PC.lnk" "$instdir\Voice Clicker PC.exe" "" "$instdir\Voice Clicker PC.exe"

MessageBox MB_OK "Setup is completed. Please reboot your computer!"

; "SimpleFC::AddApplication [name] [path] [scope] [ip_version] [remote_addresses] [status]"



SectionEnd

########################################################
# create a section to define what the uninstaller does.
# the section will always be named "Uninstall"
Section "Uninstall"

DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Name}"
SimpleFC::AdvRemoveRule "Voice Clicker PC"
# Always delete uninstaller first
Delete $INSTDIR\${UinstFile}

# now delete installed file
RMDir /R $INSTDIR 
SectionEnd
########################################################