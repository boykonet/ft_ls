package main

import (
	"fmt"
	"os"
)

func FindNextIndex(key string, args []string) int {
	for index, value := range args {
		if value == key {
			return index + 1
		}
	}
	return -1
}

func main() {
	var farr, sarr []string
	var vars []string

	vars = os.Args[1:]
	if len(vars) == 1 {
		return
	}

	for _, value := range vars {
		if len(value) != 1 {
			fmt.Printf("Error: [%v] the string must be not more than 1 symbol\n", value)
			return
		}
		farr = append(farr, value)
	}

	for i := 1; i < len(vars); i++ {

		sarr = nil

		//fmt.Println(farr)

		for _, farrvalue := range farr {
			index := FindNextIndex(farrvalue[len(farrvalue)-1:], vars)

			if index == -1 || index >= len(vars) {
				//fmt.Printf("Something went wrong [%v]\n", index)
				continue
			}
			for _, fv := range vars[index:] {
				sarr = append(sarr, farrvalue+fv)
			}
		}

		for _, v := range farr {
			fmt.Printf("\"%v\"", v)
			fmt.Print("  ")
		}
		farr = append([]string{}, sarr...)
	}

	for index, v := range farr {
		fmt.Printf("\"%v\"", v)
		if (index + 1) < len(farr) {
			fmt.Print("  ")
		}
	}
	fmt.Println()
}
