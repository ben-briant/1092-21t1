main:
    # scanf("%c", &ch);
    li $v0, 12      # We want to perform syscall #12 (read char)
    syscall         # Perform the syscall
    move $s0, $v0   # Move the scanned in char into $s0
    
    la $a0, a
    beq $s0, 'a', print
    la $a0, e
    beq $s0, 'e', print
    la $a0, i
    beq $s0, 'i', print
    la $a0, o
    beq $s0, 'o', print
    la $a0, u
    beq $s0, 'u', print
    la $a0, empty

print:
    # Print whatever string is currently in $a0
    # Since we jump here after loading the correct string,
    # it will print the correct string.
    li $v0, 4
    syscall

    # Print the newline character
    li $v0, 11
    li $a0, '\n'
    syscall

    jr $ra

    .data
a:
    .asciiz "eh? "
e:
    .asciiz "eee "
i:
    .asciiz "eye "
o:
    .asciiz "ohh "
u:
    .asciiz "you "
empty:
    .asciiz ""