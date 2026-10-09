# myls - System Programming Midterm

A simplified implementation of the NetBSD `ls(1)` command written in C for the System Programming midterm project.

---

## 1. Student Information

| Information | Details |
|---|---|
| **Name** | Doan Diep Anh |
| **Student ID** | 24ITB017 |

---

## 2. Project Description

This project implements a simplified version of the NetBSD `ls(1)` command in the C programming language.

The program is named **`myls`** and is developed based on the provided **NetBSD 10.1 `ls(1)` manual**.

The main purpose of `myls` is to:

- List files and directories.
- Display detailed file information.
- Handle hidden files.
- Sort entries using different criteria.
- Display inode and block information.
- Support recursive directory traversal.
- Classify different file types.
- Handle non-printable characters.
- Process multiple command-line options.

When the operand is a file, the program displays information about that file.

When the operand is a directory, the program lists the contents of that directory.

When no operand is specified, the program lists the contents of the current directory.

---

## 3. Supported Options

The program supports the following options:

| Option | Description |
|---|---|
| `-A` | Display all entries except `.` and `..`. |
| `-a` | Include hidden entries whose names begin with `.`. |
| `-c` | Use file status change time instead of modification time. |
| `-d` | Display the directory itself instead of listing its contents. |
| `-F` | Append a symbol indicating the file type. |
| `-f` | Disable sorting. |
| `-h` | Display file sizes in human-readable format. |
| `-i` | Display the inode number. |
| `-k` | Display block sizes in kilobytes. |
| `-l` | Display information in long format. |
| `-n` | Display numeric UID and GID instead of owner and group names. |
| `-q` | Replace non-printable characters in file names with `?`. |
| `-R` | Recursively list subdirectories. |
| `-r` | Reverse the sorting order. |
| `-S` | Sort entries by file size, largest first. |
| `-s` | Display the number of file system blocks used. |
| `-t` | Sort entries by modification time, newest first. |
| `-u` | Use access time instead of modification time. |
| `-w` | Display non-printable characters in raw form. |

---

## 4. Usage

### 4.1 General Syntax

```text
./myls [options] [file ...]
```

### 4.2 Basic Usage

List the current directory:

```sh
./myls
```

List the contents of the `testdir` directory:

```sh
./myls testdir
```

Display information about a specific file:

```sh
./myls testdir/alpha.txt
```

### 4.3 Hidden Files

Display hidden files:

```sh
./myls -a testdir
```

Display hidden files except `.` and `..`:

```sh
./myls -A testdir
```

### 4.4 Long Format

Display detailed information:

```sh
./myls -l testdir
```

Display human-readable sizes:

```sh
./myls -lh testdir
```

Display numeric UID and GID:

```sh
./myls -n testdir
```

### 4.5 Sorting

Sort by file size:

```sh
./myls -S testdir
```

Sort by file size in reverse order:

```sh
./myls -Sr testdir
```

Sort by modification time:

```sh
./myls -t testdir
```

Reverse the sorting order:

```sh
./myls -tr testdir
```

Disable sorting:

```sh
./myls -f testdir
```

### 4.6 File Information

Display inode numbers:

```sh
./myls -i testdir
```

Display block usage:

```sh
./myls -s testdir
```

Display block usage in kilobytes:

```sh
./myls -sk testdir
```

### 4.7 Recursive and Directory Modes

Recursively list subdirectories:

```sh
./myls -R testdir
```

Display the directory itself:

```sh
./myls -d testdir
```

### 4.8 File Classification

Display file type indicators:

```sh
./myls -F testdir
```

The program uses the following indicators:

| Symbol | File Type |
|---|---|
| `/` | Directory |
| `*` | Executable file |
| `@` | Symbolic link |
| `\|` | FIFO |
| `=` | Socket |

### 4.9 Non-printable Characters

Replace non-printable characters with `?`:

```sh
./myls -q testdir
```

Display non-printable characters in raw form:

```sh
./myls -w testdir
```

### 4.10 Time Selection

Use modification time:

```sh
./myls -lt testdir
```

Use access time:

```sh
./myls -ltu testdir
```

Use status change time:

```sh
./myls -ltc testdir
```

---

## 5. Module Description

### 5.1 `main.c`

Responsible for:

- Program initialization.
- Processing command-line arguments.
- Handling file and directory operands.
- Calling the appropriate processing functions.

### 5.2 `options.c`

Responsible for:

- Parsing command-line options.
- Storing option states.
- Handling option precedence.

### 5.3 `listing.c`

Responsible for:

- Opening and reading directories.
- Filtering hidden files.
- Retrieving file metadata.
- Processing directory entries.
- Recursive directory traversal.

### 5.4 `sorting.c`

Responsible for:

- Sorting entries by name.
- Sorting entries by file size.
- Sorting entries by time.
- Reversing the sorting order.
- Disabling sorting when `-f` is specified.

### 5.5 `display.c`

Responsible for:

- Normal output.
- Long-format output.
- File size formatting.
- Inode display.
- Block display.
- Owner and group display.
- File classification.
- Symbolic-link target display.
- Non-printable character handling.

### 5.6 `include/`

Contains the header files used by the source modules.

### 5.7 `testdir/`

Contains files and directories used for functional testing.

The test set includes regular files, hidden files, files with different sizes, an executable file, a symbolic link, a FIFO, nested directories, and a file containing a non-printable character.

---

## 6. Compilation

The project uses the provided Makefile.

### 6.1 Build the Program

```sh
make
```

### 6.2 Clean Compiled Files

```sh
make clean
```

After successful compilation, the executable is:

```text
myls
```

---

## 7. Testing

The program was tested on NetBSD using the following test cases.

### 7.1 Basic Listing

```sh
./myls testdir
```

### 7.2 Hidden Files

```sh
./myls -a testdir
./myls -A testdir
```

### 7.3 Long Format

```sh
./myls -l testdir
./myls -lh testdir
./myls -n testdir
```

### 7.4 Inode and Block Information

```sh
./myls -i testdir
./myls -s testdir
./myls -sk testdir
```

### 7.5 Sorting

```sh
./myls -S testdir
./myls -Sr testdir
./myls -t testdir
./myls -tr testdir
./myls -f testdir
```

### 7.6 Recursive and Directory Modes

```sh
./myls -R testdir
./myls -d testdir
```

### 7.7 File Classification

```sh
./myls -F testdir
```

### 7.8 Non-printable Characters

```sh
./myls -q testdir
./myls -w testdir
```

### 7.9 Time Selection

```sh
./myls -lt testdir
./myls -ltu testdir
./myls -ltc testdir
```

### 7.10 Option Precedence

The following combinations were tested:

```sh
./myls -ln testdir
./myls -nl testdir
./myls -Rd testdir
./myls -dR testdir
./myls -qw testdir
./myls -wq testdir
./myls -ltuc testdir
./myls -ltcu testdir
```

For option pairs that override each other, the last specified option determines the final behavior.

### 7.11 BLOCKSIZE

The `BLOCKSIZE` environment variable was tested using:

```sh
BLOCKSIZE=1024 ./myls -s testdir
```

and:

```sh
BLOCKSIZE=4096 ./myls -s testdir
```

The block count changes according to the selected block size.

### 7.12 Error Handling

An invalid file path was tested:

```sh
./myls testdir/not_found
```

Expected output:

```text
myls: testdir/not_found: No such file or directory
```

The exit status was then checked:

```sh
echo $?
```

Expected result:

```text
1
```


