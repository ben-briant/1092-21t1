
main:
    li $v0, 5
    syscall
    move $s0, $v0 # Start in $s0

    li $v0, 5
    syscall
    move $s1, $v0 # End in $s1

start_while:
    bgt $s0, $s1, end_while

    li $v0, 1
    move $a0, $s0
    syscall

    li $v0, 11
    li $a0, '\n'
    syscall

    # start = start + 1
    # li $t0, 1
    # add $s0, $s0, $t0
    addi $s0, $s0, 1

    j start_while

end_while:
    jr $ra
