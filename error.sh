echo "Test:"
$(./push_swap 0 0 | cat)
echo "Test:"
$(./push_swap 2147483649 | cat)
echo "Test:"
$(./push_swap 2147483649 1 | cat)
echo "Test:"
$(./push_swap 2147483647 1 | cat)
echo "Test:"
$(./push_swap 2147483648 1 | cat)
echo "Test:"
$(./push_swap 214748364800000000000000000000000 1 | cat)
echo "Test:"
$(./push_swap 21474836480 1 | cat)
echo "Test:"
$(./push_swap 214748364800 1 | cat)
echo "Test:"
$(./push_swap -2147483648 1 | cat)
echo "Test:"
$(./push_swap 2 -2147483648 1 | cat)
echo "Test:"
$(./push_swap 000000000002147483648 1 | cat)
echo "Test:"
$(./push_swap 00000000000214748364 1 | cat)
echo "Test:"
$(./push_swap 214748364 +1 | cat)
echo "Test:"
$(./push_swap 214748364 +1 -1 | cat)
echo "Test:"
$(./push_swap 214748364 +1 1 | cat)
echo "Test:"
$(./push_swap 214748364 01 | cat)
echo "Test:"
$(./push_swap 214748364 01 1 | cat)
echo "Test:"
$(./push_swap 214748364e 1 | cat)
echo "Test:"
$(./push_swap 214748364+ 1 | cat)
echo "Test:"
$(./push_swap 214748364 - | cat)
echo "Test:"
$(./push_swap 214748364 -0 | cat)
echo "Test:"
$(./push_swap 214748364711111111111111111111111111111111111111111111111 0 | cat)
echo "Test:"
$(./push_swap '21474836471' | cat)
echo "Test:"
$(./push_swap '21474836471' 1 | cat)
echo "Test:"
$(./push_swap '214748371' 1 | cat)
echo "Test:"
$(./push_swap "214748371" 1 | cat)
echo "Test:"
$(./push_swap "214748371           " 1 | cat)
echo "Test:"
$(./push_swap "               214748371" 1 | cat)
echo "Test:"
$(./push_swap "+-+-+-214748371" 1 | cat)
echo "Test:"
$(./push_swap "++214748371" 1 | cat)
echo "Test:"
$(./push_swap ++214748371 1 | cat)
echo "Test:"
$(./push_swap ++2171 1 | cat)
echo "Test:"
$(./push_swap | cat)
echo "Test:"
$(./push_swap ++1 3 -2 | cat)
echo "Test:"
$(./push_swap ++3 1 | cat)
echo "Test:"
$(./push_swap --3 1 | cat)
echo "Test:"
$(./push_swap 2 --3 1 | cat)
echo "Test:"
$(./push_swap ++2171 1 5 | cat)
echo "Test:"
$(./push_swap +2171 1 5 | cat)
echo "Test:"
$(./push_swap +2171 1 5 | cat)
echo "Test:"
$(./push_swap +2171 1 5 | cat)
echo "Test:"
$(./push_swap ++2171 1 5 | cat)
echo "Test:"
$(./push_swap ++2171 1 5 | cat)
echo "Test:"
$(./push_swap +2171 1 5 | cat)
echo "Test:"
$(./push_swap ++2171 0 1 | cat)
