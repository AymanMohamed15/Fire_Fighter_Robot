# define SET_BIT(num,bit) num=num|(1<<bit)
# define CLR_BIT(num,bit) num=num&(~(1<<bit))
# define GET_BIT(num,bit) (num>>bit)&1
# define TOGGLE_BIT(num,bit) num=num^(1<<bit)