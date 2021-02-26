
main:
    addi $sp, $sp, -4
    sw $ra, ($sp)

    # TODO: Complete me!
    li $a0, 3
    jal message

    lw $ra, ($sp)
    addi $sp, $sp, 4

    jr $ra

addOne:
    addi $sp, $sp, -4
    sw $s0, ($sp)

    addi $s0, $a0, 1
    move $v0, $s0

    lw $s0, ($sp)
    addi $sp, $sp, 4
    
    jr $ra

message:
    addi $sp, $sp, -8
    sw $ra, ($sp)
    sw $s0, 4($sp)

    # TODO: Complete me!
    # Our argument is already in $a0
    move $s0, $a0       # d in $t1
    jal addOne

    move $t0, $v0       # age in $t0

    li $v0, 4
    la $a0, iam
    syscall

    li $v0, 1
    move $a0, $t0
    syscall

    li $v0, 11
    li $a0, '\n'
    syscall

    li $v0, 4
    la $a0, iused
    syscall

    # How to get d?
    li $v0, 1
    move $a0, $s0
    syscall

    li $v0, 11
    li $a0, '\n'
    syscall

    lw $ra, ($sp)
    lw $s0, 4($sp)
    addi $sp, $sp, 8

    jr $ra

    .data
iam:
    .asciiz "I am "
iused:
    .asciiz "I used to be "    

