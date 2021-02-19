main:
    li $v0, 5
    syscall
    move $s0, $v0   # n in $s0

    # TODO: Finish this
    li $t0, 0 # i in $t0

start_1:
    bge $t0, $s0, end_1

    li $t1, 0 # j in $t1

start_2:
    bge $t1, $s0, end_2

    li $v0, 11
    li $a0, '*'
    syscall

    addi $t1, $t1, 1

    j start_2

end_2:
    li $v0, 11
    li $a0, '\n'
    syscall

    addi $t0, $t0, 1

    j start_1
    
end_1:
    jr $ra