# Cat-Linux
Lightweight C-based clone of the Unix cat utility using system calls like read(), write(), and open(). Includes support for -n (line numbering), -e (show $ at line ends), and -s (squeeze blank lines), demonstrating low-level file I/O and argument parsing.

✨ Features<br>
📄 Display file contents<br>
🔢 Line numbering (-n)<br>
💲 Show end-of-line markers (-e)<br>
🧹 Squeeze blank lines (-s)<br>
⚙️ Built using open(), read(), and write()<br>
🚀 Usage<br>
Compile<br>
```
gcc -o mycat mycat.c
```
Run<br>
```
./mycat [options] file1 file2 ...
```

🧩 Options<br>
Flag	Description
-n	Number all output lines
-e	Display $ at the end of each line
-s	Suppress repeated empty lines
📌 Examples<br>
```
./mycat file.txt
```
Display contents of file.txt<br>
```
./mycat -n file.txt
```
Show file with line numbers<br>
```
./mycat -e file.txt
```
Show $ at the end of each line<br>
```
./mycat -nse file.txt
```
Combine all supported options<br>
🛠️ How It Works<br>
This project avoids high-level I/O functions and instead uses system calls.<br>
open() is used to access files.<br>
read() processes input byte-by-byte.<br>
write() and dprintf() handle output.<br>
⚠️ Notes<br>
The program reads files one character at a time for simplicity.<br>
Basic error handling is included for missing files.<br>
Behavior is inspired by cat, but not a full replacement.<br>
🎯 Purpose<br>
This project was built as a learning exercise.<br>
It helps understand low-level file descriptors.<br>
It provides practice with argument parsing in C.<br>
It explores how common Unix utilities work internally.<br>
