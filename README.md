# Pipe Operator Implementation in C

This project aims to imitate the functionality of the pipe operator (`|`) found in various shell and programming languages. The programm is written in C.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)

## Introduction

The pipe operator in C allows the output of one program or function to serve as the input of another, enabling the creation of powerful data processing pipelines. This project provides a program imitating the pipe operator.

## Features

- Imitates the pipe operator (`|`) behavior found in various shell and programming languages.
- Allows chaining of multiple functions in a pipeline.
- Provides an intuitive and compact syntax for writing data processing pipelines in C.
- Supports both synchronous and asynchronous execution of functions.
- Enables the passing of data between functions via standard input and output streams.

## Installation

To use the pipe operator imitation program, follow these steps:

1. Clone the repository:

   ```
   git clone https://github.com/qnert/pipex.git
   ```

2. Move into the directory "pipex" and "make".

## USAGE
1. The program can be executed as the following structure:

   ```
   ./pipex infile "command-1" "command-2" "..." "command-n" outfile
   ```
 2. Bonus feature is the use of the here-document:

    ```
    ./pipex here_doc LIMITER "command-1" "command-2" "..." "command-n" outfile
    ```
