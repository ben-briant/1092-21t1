
main:
    # Function prologue
    addi $sp, $sp, -4
    sw $ra, ($sp)
    # TODO: Complete this
    jal message

    li $v0, 4
    la $a0, return
    syscall
    
    # Function epilogue
    lw $ra, ($sp)
    addi $sp, $sp, 4

    li $v0, 0
    jr $ra

message:
    li $v0, 4
    la $a0, greeting
    syscall

    jr $ra

    .data
greeting:
    .asciiz "Hey it is me!\n"
return:
    .asciiz "Back from function!\n"
