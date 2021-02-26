main:
    addi $sp, $sp, -4
    sw $ra, ($sp)

    li $a0, 9
    li $a1, 1
    li $a2, 7
    li $a3, 4
    # TODO: How do we pass the 5th argument?
    jal addMany

    # value returned in $v0, so move into $a0
    move $a0, $v0
    jal message

    lw $ra, ($sp)
    addi $sp, $sp, 4
    
    jr $ra

addMany:
    # TODO: Implement this function

message:
    move $t0, $a0
    la $a0, iam
    li $v0, 4
    syscall

    move $t0, $a0
    li $v0, 1
    syscall

    li $a0, '\n'
    li $v0, 11
    syscall

    jr $ra

    .data
iam:
    .asciiz "I am "
