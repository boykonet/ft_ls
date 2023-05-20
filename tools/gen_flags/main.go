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

	//m := map[string]bool{
	//	"R":     true,
	//	"r":     true,
	//	"a":     true,
	//	"l":     true,
	//	"t":     true,
	//	"Rr":    true,
	//	"Ra":    true,
	//	"Rl":    true,
	//	"Rt":    true,
	//	"ra":    true,
	//	"rl":    true,
	//	"rt":    true,
	//	"al":    true,
	//	"at":    true,
	//	"lt":    true,
	//	"Rra":   true,
	//	"Rrl":   true,
	//	"Rrt":   true,
	//	"Ral":   true,
	//	"Rat":   true,
	//	"Rlt":   true,
	//	"ral":   true,
	//	"rat":   true,
	//	"rlt":   true,
	//	"alt":   true,
	//	"Rral":  true,
	//	"Rrat":  true,
	//	"Rrlt":  true,
	//	"Ralt":  true,
	//	"ralt":  true,
	//	"Rralt": true,
	//}

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
		for _, farrvalue := range farr {
			index := FindNextIndex(farrvalue[len(farrvalue)-1:], vars)

			if index == -1 || index >= len(vars) {
				continue
			}
			for _, fv := range vars[index:] {
				sarr = append(sarr, farrvalue+fv)
			}
		}

		for _, v := range farr {
			//_, ok := m[v]
			//if ok == true {
			//	continue
			//}
			fmt.Printf("\"G%v\"", v)
			fmt.Print("  ")
		}
		farr = append([]string{}, sarr...)
	}

	for index, v := range farr {
		//_, ok := m[v]
		//if ok == true {
		//	continue
		//}
		fmt.Printf("\"G%v\"", v)
		if (index + 1) < len(farr) {
			fmt.Print("  ")
		}
	}
	fmt.Println()
}
