CSE 7359 Lab 2 README
---------------------
1.  Compile source code tell_secret.c with the following command:
    (Add -g if debug info in the executable is desired.)

    gcc -fno-stack-protector -o tell_secret tell_secret.c

2.  The program takes 2 input variables from the user and reveal a secret to
her if the access control is satisfied.

3.  A successful exploit will bypass the authorization to have the secret
revealed.

4.  Logisitics to facilitate your exploit process:
        1) Uncompress the file cse7359_lab2_src_lin.tar.gz
           (Example:  tar -xvzf cse7359_lab2_src_lin.tar.gz)
        2) Place the file root_secret in the /root directory.
        3) Use adduser command to add new user(s) (one is sufficient) to your system.

