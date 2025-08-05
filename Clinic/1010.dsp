# Microsoft Developer Studio Project File - Name="main" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=main - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "1010.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "1010.mak" CFG="main - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "main - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "main - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "main - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "main - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "main - Win32 Release"
# Name "main - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CAdmin.cpp
# End Source File
# Begin Source File

SOURCE=.\CAdminWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CButton.cpp
# End Source File
# Begin Source File

SOURCE=.\CControl.cpp
# End Source File
# Begin Source File

SOURCE=.\CData.cpp
# End Source File
# Begin Source File

SOURCE=.\CDoctor.cpp
# End Source File
# Begin Source File

SOURCE=.\CDoctorCx.cpp
# End Source File
# Begin Source File

SOURCE=.\CDoctorJjxx.cpp
# End Source File
# Begin Source File

SOURCE=.\CDoctorjzjl.cpp
# End Source File
# Begin Source File

SOURCE=.\CDoctorKsxl.cpp
# End Source File
# Begin Source File

SOURCE=.\CDoctorNew.cpp
# End Source File
# Begin Source File

SOURCE=.\CDoctorWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CDoctorXg.cpp
# End Source File
# Begin Source File

SOURCE=.\CDoctorXl.cpp
# End Source File
# Begin Source File

SOURCE=.\CDoctorZw.cpp
# End Source File
# Begin Source File

SOURCE=.\CEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\CJiuzhen.cpp
# End Source File
# Begin Source File

SOURCE=.\CKeshi.cpp
# End Source File
# Begin Source File

SOURCE=.\CKeshiCx.cpp
# End Source File
# Begin Source File

SOURCE=.\CKserror.cpp
# End Source File
# Begin Source File

SOURCE=.\CLabel.cpp
# End Source File
# Begin Source File

SOURCE=.\CLoginWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CMainWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CSigninWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CTable.cpp
# End Source File
# Begin Source File

SOURCE=.\CTool.cpp
# End Source File
# Begin Source File

SOURCE=.\CUser.cpp
# End Source File
# Begin Source File

SOURCE=.\CUserCx.cpp
# End Source File
# Begin Source File

SOURCE=.\CUserGrzx.cpp
# End Source File
# Begin Source File

SOURCE=.\CUserJzxx.cpp
# End Source File
# Begin Source File

SOURCE=.\CUserQh.cpp
# End Source File
# Begin Source File

SOURCE=.\CUserQhxg.cpp
# End Source File
# Begin Source File

SOURCE=.\CUserwin.cpp
# End Source File
# Begin Source File

SOURCE=.\CUserXg.cpp
# End Source File
# Begin Source File

SOURCE=.\CUserxx.cpp
# End Source File
# Begin Source File

SOURCE=.\CuserYy.cpp
# End Source File
# Begin Source File

SOURCE=.\CUserYymain.cpp
# End Source File
# Begin Source File

SOURCE=.\CWindow.cpp
# End Source File
# Begin Source File

SOURCE=.\Cxiala.cpp
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CAdmin.h
# End Source File
# Begin Source File

SOURCE=.\CAdminWin.h
# End Source File
# Begin Source File

SOURCE=.\CButton.h
# End Source File
# Begin Source File

SOURCE=.\CControl.h
# End Source File
# Begin Source File

SOURCE=.\CData.h
# End Source File
# Begin Source File

SOURCE=.\CDoctor.h
# End Source File
# Begin Source File

SOURCE=.\CDoctorCx.h
# End Source File
# Begin Source File

SOURCE=.\CDoctorJjxx.h
# End Source File
# Begin Source File

SOURCE=.\CDoctorjzjl.h
# End Source File
# Begin Source File

SOURCE=.\CDoctorKsxl.h
# End Source File
# Begin Source File

SOURCE=.\CDoctorNew.h
# End Source File
# Begin Source File

SOURCE=.\CDoctorWin.h
# End Source File
# Begin Source File

SOURCE=.\CDoctorXg.h
# End Source File
# Begin Source File

SOURCE=.\CDoctorXl.h
# End Source File
# Begin Source File

SOURCE=.\CDoctorZw.h
# End Source File
# Begin Source File

SOURCE=.\CEdit.h
# End Source File
# Begin Source File

SOURCE=.\CJiuzhen.h
# End Source File
# Begin Source File

SOURCE=.\CKeshi.h
# End Source File
# Begin Source File

SOURCE=.\CKeshiCx.h
# End Source File
# Begin Source File

SOURCE=.\CKserror.h
# End Source File
# Begin Source File

SOURCE=.\CLabel.h
# End Source File
# Begin Source File

SOURCE=.\CLoginWin.h
# End Source File
# Begin Source File

SOURCE=.\CMainWin.h
# End Source File
# Begin Source File

SOURCE=.\CSigninWin.h
# End Source File
# Begin Source File

SOURCE=.\CTable.h
# End Source File
# Begin Source File

SOURCE=.\CTool.h
# End Source File
# Begin Source File

SOURCE=.\CUser.h
# End Source File
# Begin Source File

SOURCE=.\CUserCx.h
# End Source File
# Begin Source File

SOURCE=.\CUserGrzx.h
# End Source File
# Begin Source File

SOURCE=.\CUserJzxx.h
# End Source File
# Begin Source File

SOURCE=.\CUserQh.h
# End Source File
# Begin Source File

SOURCE=.\CUserQhxg.h
# End Source File
# Begin Source File

SOURCE=.\CUserwin.h
# End Source File
# Begin Source File

SOURCE=.\CUserXg.h
# End Source File
# Begin Source File

SOURCE=.\CUserxx.h
# End Source File
# Begin Source File

SOURCE=.\CuserYy.h
# End Source File
# Begin Source File

SOURCE=.\CUserYymain.h
# End Source File
# Begin Source File

SOURCE=.\CWindow.h
# End Source File
# Begin Source File

SOURCE=.\Cxiala.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
