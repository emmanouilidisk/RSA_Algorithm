<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/othneildrew/Best-README-Template">
    <img src="logo.png" alt="Logo" width="70" height="70">
  </a>
  <h3 align="center">RSA Algorithm Implementation</h3>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#contributing">Contributing</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project
The repository includes a class implementing RSA algorithm, an example showing its use and a script to test it. 
The algorithm was implemented in the Computer Systems Security course of the 9th semester of DUTh.
<p align="center">
<img src="https://github.com/emmanouilidisk/computer_system_security/blob/main/Demonstration.gif" align="center" width="557" height="300" />
</p>  

The implementation uses:
- two primes to calculate n    
- extended GCD method to find the private key(d)    
- Miller-Rabin for primality checking  
- key size 2048 (but it can be easily adjusted for any key size)  


<!-- GETTING STARTED -->
## Getting Started
To get started make sure you have installed all the prerequisites in your computer and then follow the instuctions in the installation section.

### Prerequisites
To compile this implementation of RSA you will need:
- [cmake](https://cmake.org/download/)
- [boost](https://www.boost.org/users/download/) library, which can also be extracted from the 7z included
  - Make sure to include the path of the library in the CMakeLists
- A compiler that supports std11 and threading
  - (This project was tested with [mingw64](http://mingw-w64.org/doku.php) version 8)

### Installation
To run the example: 
- Open the example folder and type:
```
mkdir build
cd build
cmake ..
make
```
- Add a file named plain.txt with the message you want to encrypt before running the output file.

To run the tests, follow the same procedure.


<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be, learn, inspire, and create.  
Contribute following the above steps:

1. Fork the Project
2. Create your Feature Branch (`git checkout -b new_branch_name`)
3. Commit your Changes (`git commit -m 'Add some extra functionality'`)
4. Push to the Branch (`git push origin new_branch_name`)
5. Open a Pull Request  

Link Overleaf: https://www.overleaf.com/5377759678bsryrnmtscdk

Google Slides: https://docs.google.com/presentation/d/1MA-u-ZCHSACHJGZN0hokGA0RBlDJ-mfX0qpQqUVqWjA/edit?usp=sharing  



