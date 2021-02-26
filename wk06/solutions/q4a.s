
main:
    addi $sp, $sp, -4
    sw $ra, ($sp)

    jal message

    lw $ra, ($sp)
    addi $sp, $sp, 4

    jr $ra

message:
    la $a0, greeting
    li $v0, 4
    syscall

    jr $ra

    .data
greeting:
    .asciiz "Hey it is me!\n"
