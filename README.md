<h1 align="center">
	42 Project - Minishell
</h1>

<p align="center">
	<b><i> As beautiful as a shell !</i></b>
</p>

<p align="center">
	<img src="https://github.com/Luma-3/Luma-3/blob/main/badges/push_swapm.png" alt="push_swap_logo" />
</p>

---
<p align="center">
	<img src="https://img.shields.io/badge/Score-125-blue?style=flat-square&logo=42" alt="Score project :125"/>
	<img alt="Static Badge" src="https://img.shields.io/badge/Outstanding-2-blue?style=flat-square&logo=42">
	<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/Luma-3/Push-Swap?style=flat-square&logo=github">
</p>




## Overview

This project serves an educational purpose and is based on the **common core of 42 School**. Therefore, it is subject to educational restrictions. Please be aware of these restrictions before making any contributions.

Please note that due to the private nature of the subject, it cannot be publicly shared on this GitHub repository.


## 📄 Description

This project aims to sort a stack A using another stack B with the fewest possible moves!

The available operations are as follows:

    (sa): Swap on A
    (sb): Swap on B
    (ss): Swap on A and B
    (pa): Push the first element of B onto A
    (pb): Push the first element of A onto B
    (ra): Rotate A
    (rb): Rotate B
    (rr): Rotate A and B
    (rra): Reverse rotation of A
    (rrb): Reverse rotation of B
    (rrr): Reverse rotation of A and B

Three limits are defined as follows:

    3 numbers: maximum of 5 moves
    100 numbers: maximum of 700 moves
    500 numbers: maximum of 5500 moves

This project does not aim to be the fastest, but out of a sense of perfectionism, I have optimized its performance to the maximum: `0.03s user 0.00s system 98% CPU 0.031s total` for 500 numbers.

Algorithms used:

Two algorithms coexist: the Turkish algorithm and a median value sorting algorithm.

## 📥 Installation

Installation and compilation commands :

```
git clone --recursive https://github.com/Luma-3/Push-Swap.git
cd Push-Swap
make
```

## 🦆 Usage

For launch Sorter :
```
./push_swap $ARG
or
./push_swap [arg1] [arg2] ...
```

## Performance 



This work is published under the terms of **[42 Unlicense](https://github.com/gcamerli/42unlicense)**.
