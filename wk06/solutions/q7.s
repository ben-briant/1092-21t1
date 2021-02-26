main:
    addi $sp, $sp, -4
    sw $ra, ($sp)

    li $a0, 9
    li $a1, 1
    li $a2, 7
    li $a3, 4

    # TODO: How do we pass the 5th argument?
    addi $sp, $sp, -4       # Allocate space on the stack for the argument
    li $t0, 5
    sw $t0, ($sp)

    jal addMany

    addi $sp, $sp, 4        # Deallocate the stack space used for the argument

    # value returned in $v0, so move into $a0
    move $a0, $v0
    jal message

    lw $ra, ($sp)
    addi $sp, $sp, 4
    
    jr $ra

addMany:
    # Note: This function has no stack, since we don't need to save $ra,
    # or any of the $s registers.
    # The stack is only used for storing the old $fp.
    addi $sp, $sp, -4
    sw $fp, ($sp)
    la $fp, ($sp)         # Load the new frame pointer

    move $v0, $a0
    add $v0, $v0, $a1
    add $v0, $v0, $a2
    add $v0, $v0, $a3

    # Now, grab the argument from the stack (just above the start of our frame)
    lw $t0, 4($fp)
    add $v0, $v0, $t0

    la $fp, ($sp)
    addi $sp, $sp, 4

    jr $ra


message:
    move $t0, $a0
    la $a0, iam
    li $v0, 4
    syscall

    move $a0, $t0
    li $v0, 1
    syscall

    li $a0, '\n'
    li $v0, 11
    syscall

    jr $ra

    .data
iam:
    .asciiz "I am "
