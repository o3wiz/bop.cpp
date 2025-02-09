set(HDRS
	"include/bop/Bop.hpp"
)

add_library(bop INTERFACE ${HDRS})

target_include_directories(bop INTERFACE "include")
