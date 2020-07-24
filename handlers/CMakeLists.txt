message("----------------------handlers begin-------------------------")

foreach(x IN LISTS A C)
   message("x = " ${x})
endforeach()

#print_me()

set(C "lower" PARENT_SCOPE)
message("C is " ${C})

message("----------------------handlers end---------------------------")