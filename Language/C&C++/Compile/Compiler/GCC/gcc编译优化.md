<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dmjcb
 * @Email: 
 * @Date: 2023-03-09 01:34:22
 * @LastEditors: dmjcb
 * @LastEditTime: 2023-03-10 14:15:08
-->

# 编译优化

## -O1

在不影响编译速度的情况下, 尽量采取一些优化算法降低代码大小和加快代码运行的速度, 并启用以下优化选

### -fauto-inc-dec

地址访问时, 合并地址访问指令和地址的递增和递减操作

### -fbranch-count-reg

在计数寄存器中运行递减和分支指令
而不是单独运行递减指令, 并与零比较, 然后再根据结果进行分支

### -combine-stack-adjustments

跟踪堆栈的push和pop, 并尝试找到合并它们的方法

### -fcompare-elim

判断计算结果的flag寄存器, 如果可以, 用flag寄存器的结果来代替现式地比较操作

### fcprop-registers

通过寄存器存有的值, 通过计算变量的依赖, 减少从内存中读取该变量的值, 通过拷贝传播, 来减少变量的拷贝

### -fdce

消除死代码

### -fdefer-pop

程序一般在函数返回时, 会pop出栈中元素
而编译器, 会合并多个函数调用, 并一次性pop出相关的元素

#### -fdelayed-branch

尝试对指令重新排序, 来利用延迟分支指令后可用的指令槽

### -fdse

对死代码进行消除

### -fforward-propagate

The pass tries to combine two instructions and checks if the result can be simplified. If loop unrolling is active, two passes are performed and the second is scheduled after loop unrolling.

### -fguess-branch-probability

分支预测

### -fif-conversion2

利用条件执行把if条件转化为无分支等价代码

### -fif-conversion

利用moves, min, max, set, abs等手段把if条件转化为无分支等价代码

### -finline-functions-called-once

把静态函数转为inline函数

### -fipa-pure-const

发现函数是纯函数还是常量函数

### -fipa-profile

对cold(仅调用一次的函数)函数进行优化

### -fipa-reference

### -fmerge-constants

合并常数计算

### -fmove-loop-invariants

优化循环的不变量

### -freorder-blocks

对编译后的函数中的基本块进行重新排序, 以减少所采取的分支数量, 提高代码的定位性. 

### -fshrink-wrap

函数的开场白仅在使用前才初始化, 而不是在函数开始的时候做

### -fshrink-wrap-separate

把函数的开场白和结束语分开, 尽在使用的时候才初始化

### -fsplit-wide-types

对于某些需要占用多个寄存器的变量, 独立的申请寄存器

### -fssa-backprop

在定义链上传播相关使用的信息, 来简化定义

### -fssa-phiopt

优化条件代码

### -fstore-merging

合并存储

## -O2

尝试更多的寄存器级的优化以及指令级的优化, 会在编译期间占用更多的内存和编译时间

### -fthread-jumps

判断是否有double jump, 并进行优化

### -falign-functions

把函数的开始地址对齐到2的幂

### -falign-jumps

把分支的起点地址对齐到2的幂

### -falign-loops

把循环的开始地址对齐到2的幂

### -falign-labels

把标签的地址对齐到2的幂

### -fcaller-saves

### -fcrossjumping

### -fcse-follow-jumps

### -fcse-skip-blocks

### -fdelete-null-pointer-checks

检查是否存在delete空指针

### -fdevirtualize

### -fdevirtualize-speculatively

用子类虚函数覆盖虚函数函数指针, 将对虚拟函数的调用转换为直接调用

### -fexpensive-optimizations

### -fgcse

### -fgcse-lm

全局的公用子表达式优化

### -fhoist-adjacent-loads

### -finline-small-functions

把小函数优化为内联函数

### -findirect-inlining

### -fipa-cp

过程间常数传播

### -fipa-cp-alignment

### -fipa-bit-cp

### -fipa-sra

过程间优化, 删除未使用的参数, 将值传递优化为引用传递

### -fipa-icf

### -fisolate-erroneous-paths-dereference

检测由于取消空指针而触发错误或未定义行为的路径, 将这些路径隔离

### -flra-remat

通过上下文敏感, 重用变量

### -foptimize-sibling-calls

优化同级和尾部递归调用

### -foptimize-strlen

优化strlen函数

### -fpartial-inlining

部分内联函数

### -fpeephole2

机器相关优化

### -freorder-blocks-algorithm=stc

块内代码重排优化

### -freorder-blocks-and-partition

### -freorder-functions

重排代码

### -frerun-cse-after-loop

重新运行公共表达式减少在循环后


### -fsched-interblock
### -fsched-spec
在不同块间进行重排指令

### -fschedule-insns
### -fschedule-insns2 
### -fstrict-aliasing
类型严格转换检查

### -fstrict-overflow
检查类型是否溢出

### -ftree-builtin-call-dce 
### -ftree-switch-conversion
### -ftree-tail-merge 
### -fcode-hoisting 
### -ftree-pre 
### -ftree-vrp 
### -fipa-ra
函数调用者, 如果某些寄存器没有用到, 则可以不需要保存这些寄存器的值

## -O3

除了执行O2所有的优化选项之外, 一般还会采用很多向量化算法, 提高程序的并行度, 并利用CPU的流水线和cache来加快运行速度, 

这个选项会加大代码的大小, 并降低目标代码的执行时间

### -finline-functions
采用一些启发式算法对函数进行内联

### -funswitch-loops
找到循环的不变条件, 并移到循环外部

### -fpredictive-commoning
在循环间重用计算

### -fgcse-after-reload
执行全局的共同子表达式消除

### -ftree-loop-vectorize　
向量化优化

### -ftree-loop-distribute-patterns
把loop的某些部分转化为标准函数, 例如memset

### -fsplit-paths
### -ftree-slp-vectorize
基本块向量化

### -fvect-cost-model
### -ftree-partial-pre
部分冗余代码消除

### -fpeel-loops
### -fipa-cp-clone
过程间调用函数克隆, 让常量传播更有效

## -Os

目的是尽量减少目标代码的大小, 这对存储容量很小的设备尤为重要

### -falign-functions
对齐

### -falign-jumps
对齐

### -falign-loops
对齐

### -falign-labels
对齐

### -freorder-blocks
重排

### -freorder-blocks-algorithm=stc
重排

### -freorder-blocks-and-partition
重排

### -fprefetch-loop-arrays
预取
