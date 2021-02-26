
main:
    addi $sp, $sp, -4
    sw $ra, ($sp)

    li $a0, 5
    jal rec

    lw $ra, ($sp)
    addi $sp, $sp, 4

    jr $ra

rec:
    addi $sp, $sp, -4
    sw $ra, ($sp)

    move $t1, $a0

    beqz $a0, if
    # n is already in $a0
    li $v0, 1
    syscall
    li $a0, '\n'
    li $v0, 11
    syscall
    addi $a0, $t1, -1
    jal rec

    j end_rec

if:
    la $a0, goodbye
    li $v0, 4
    syscall
    j end_rec

end_rec:
    lw $ra, ($sp)
    addi $sp, $sp, 4
    jr $ra

    .data
goodbye:
    .asciiz "Goodbye\n"
