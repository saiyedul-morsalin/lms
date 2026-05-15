# 📚 Console-Based E-Learning Management System (LMS) in C

A modular, high-performance **Learning Management System (LMS)** built in pure C, designed to simulate the complete lifecycle of an e-learning platform using a console-based interface.

This project demonstrates **low-level system design, modular architecture, and file-based persistence**, making it ideal for understanding how large-scale software systems can be engineered from scratch.

---

## 🚀 Project Vision

The goal of this project is to:

- Build a **full LMS core engine** using C
- Apply **real-world software architecture principles**
- Simulate **SaaS-level backend logic**
- Provide a foundation for future **web/API-based LMS systems**

---

## 🧱 Core Features

### 👤 User & Access Layer
- User Registration & Login
- Role-Based Access Control:
  - 👨‍🎓 Student
  - 👨‍🏫 Instructor
  - 🛠 Admin
- Persistent user storage (binary files)

---

### 📚 Course Management
- Create and manage courses
- Instructor-specific course ownership
- Course listing system
- Scalable structure for modules/lessons

---

### 🧠 System Architecture
- Modular design using `.h` (interface) and `.c` (implementation)
- Clean separation of concerns
- Extensible system components:
  - `auth` → authentication
  - `course` → course logic
  - `utils` → helper functions
  - `storage` → persistence layer

---

### 💾 Data Persistence
- Binary file storage (`.dat`)
- Efficient struct-based read/write
- No external database dependency
- Easily extendable to indexing or DB layer

---

### 🖥️ CLI Interface
- Menu-driven interaction
- Lightweight and fast execution
- SSH-compatible for remote environments

---

### 🔄 Multi-Session Support
- Multiple concurrent sessions using `tmux`
- Independent runtime per session
- Designed for server-based CLI usage

---

## 🗂️ Project Structure
lms/
├── src/
│ ├── main.c
│ ├── auth.c
│ ├── course.c
│ ├── utils.c
│ └── storage.c
├── include/
│ ├── auth.h
│ ├── course.h
│ ├── utils.h
│ └── storage.h
├── data/
│ ├── users.dat
│ └── courses.dat
├── Makefile
└── README.md


---

## ⚙️ Installation

### Prerequisites

- Linux / Ubuntu
- GCC Compiler

Install required tools:

```bash
sudo apt update
sudo apt install build-essential
make
./lms

# 🌐 Server Access

This guide explains how to access the LMS on a remote Ubuntu server and run it via SSH.

---

## 🖥️ Server Information

- Domain: `lms.saiyedulmorsalin.me`
- User: `saiyedul`
- Pass: `asdf@#`

---

## 🔐 1. Connect to Server (SSH)

### Using IP:
```bash
ssh saiyedul@lms.saiyedulmorsalin.me
```

