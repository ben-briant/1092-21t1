main:
    # scanf("%c", &ch);
    li $v0, 12      # We want to perform syscall #12 (read char)
    syscall         # Perform the syscall
    move $s0, $v0   # Move the scanned in char from $v0 into $s0
    
    # TODO: Implement the switch statement

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