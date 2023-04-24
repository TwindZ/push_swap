# Push Swap Project

This is the Push Swap project for the 42 Québec school. The goal of the project is to create a program that sorts a stack of integers using only two stacks and a limited set of operations.

## How to Run

To compile the program, run the following command in the root directory of the project:

### Usage
```bash
make
```
To run the program, execute the following command:

```bash
./push_swap nb1 nb2 nb3 ...
```
or
```bash
./push_swap "nb1 nb2 nb3" ... 
```

## Output

The output of the program is a list of action to sort the list

## Action
- _pa_	: push the top node of the stack "a" to the top of the stack a
- _pb_	: push the top node of the stack "a" to the top of the stack b
- _sa_	: swap the first two elements of stack a
- _sb_	: swap the first two elements of stack b
- _ss_	: swap the first two elements of both stacks
- _ra_	: switch the first element of stack a to the last position
- _rb_	: switch the first element of stack b to the last position
- _rra_	: switch the last element of stack a to the top position
- _rrb_	: switch the last element of stack b to the top position
- _rrr_	: Switch the top element of both stacks with the last element of each respective stack.

## Algorithm Details

I opted to use the radix algorithm for sorting numbers, which was optimized through a prior simulation to determine the base that minimizes the number of operations required. To facilitate the detection of the order of elements in the sorted list, I decided to use indices rather than the integers themselves, employing the following formula to determine the numbers to transfer from one stack to another: (index / data->div) % base == mod.

In this formula, *_index_* represents the index of the number to be sorted, *_div_* denotes the divisor, *_base_* is the base determined by the simulation and *_mod_* is the modulo to look for the push. The *_index_* is initially divided by 1, and the program looks for numbers with a modulo of 0 to transfer to the corresponding stack. Subsequently, _*mod*_ is incremented, and the program searches for numbers with a modulo of 1, followed by 2, and so on until _*mod*_ reaches the value of (_*base_* - 1). This process continues until all the numbers are pushed. *_div_* is then multiplied by the *_base_*, and the process is repeated until the list is completely sorted.

It is worth noting that this algorithm is highly effective for large lists of numbers but less so for smaller ones. Therefore, I have devised specific algorithms for sorting lists with fewer than ten numbers. The radix algorithm takes over for larger lists.

## Contributors

- [Emmanuel Lamothe](https://github.com/TwindZ)