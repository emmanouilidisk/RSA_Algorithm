```diff
This repository was created for the subject computer system security.
-This implementation is not appropriate for professional use as it lacks important features 
```
# RSA Algorithm Implementation   
This repository includes a class that implements rsa, an example and a script to test it.
The implementation uses two primes to calculate n, extended GCD method to find d and Miller-Rabin for primality check.
The key size is 2048 but it can easily be adjusted for any key size.
## Dependencies
To compile this implementation of RSA you will need
- [cmake](https://cmake.org/download/)
- [boost](https://www.boost.org/users/download/) library, which can also be extracted from the 7z included
  - Make sure to include the path of the library in the CMakeLists
- A compiler that supports std11 and threading
  - (This project was tested with [mingw64](http://mingw-w64.org/doku.php) version 8)
## Execution
To run an example open the example folder and type
```
mkdir build
cd build
cmake ..
make
```
Add a file named plain.txt with the message you want to encrypt before running the output file

To run the tests, follow the same procedure


Link Overleaf: https://www.overleaf.com/5377759678bsryrnmtscdk

Google Slides: https://docs.google.com/presentation/d/1MA-u-ZCHSACHJGZN0hokGA0RBlDJ-mfX0qpQqUVqWjA/edit?usp=sharing  
Google Themes: 
- https://slidesgo.com/theme/tech-company-branding-guidelines
- https://slidesgo.com/theme/honeycomb-project-proposal
