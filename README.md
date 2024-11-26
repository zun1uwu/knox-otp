# knox-otp
C99 Implementation of the one-time pad "unbreakable" encryption.

# What is this?
In cryptography, the one-time pad (OTP) is an encryption technique that cannot be cracked, but requires the use of a single-use pre-shared key that is larger than or equal to the size of the message being sent.

Learn more: https://en.wikipedia.org/wiki/One-time_pad

# Syntax
`knox [e|d] [input file] [key file]`

If you encrypt a file, the key file argument will serve as the output path for the resulting key.
If you decrypt a file, you need to provide the path for an existing key that will be used to decrypt the file.

# Building
Run `make`

# Dependencies
- C compiler
- C standard library
