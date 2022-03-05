<!--
 * @Author: xinyu Li
 * @Date: 2021-10-18 16:06:11
 * @LastEditTime: 2022-02-12 16:13:43
 * @Description: 
 * @FilePath: \helloworld\fuck\Tree\readme.md
 * I am because you are
-->
## 二叉树函数中的参数问题

>一般二叉树节点结构体中由指针存储左右子节点，该指针指向存储左右子节点数据的地址。在函数中一般传递的是Node* 指针，而不是Node结构体。并且一般修改结构体内数据用Node*，修改结构体指针本身时用Node*&