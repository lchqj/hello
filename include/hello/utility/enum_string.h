#ifndef _HELLO_ENUM_STRING_H_
#define _HELLO_ENUM_STRING_H_

#define HELLO_ENUM_BEGIN(EnumType)                           \
namespace EnumType                                           \
{                                                            \
    enum ___enum                                             \
    {                                                        \

#define HELLO_ENUM_END()                                     \
        ___unkown                                            \
    };                                                       \
    class value                                              \
    {                                                        \
    private:                                                 \
	    value()                                              \
	    {								                     \
	    }								                     \
    public:                                                  \
        value(int nValue)                                    \
        {								                     \
            ___value = (___enum)nValue;                      \
        }								                     \
	    value(___enum e)                                     \
	    {								                     \
		    ___value = e;				                     \
	    }								                     \
	    operator int() const			                     \
	    {								                     \
		    return ___value;			                     \
	    }								                     \
        const char* c_str()const;                            \
    private:							                     \
	    ___enum ___value;				                     \
    };                                                       \
}     


#define HELLO_ENUM_STR_IMPL(EnumType)                        \
namespace EnumType                                           \
{                                                            \
    struct EnumType::___tostr ___tostr::inst;                \
}

#define HELLO_ENUM_STR_BEGIN(EnumType)                       \
namespace EnumType                                           \
{                                                            \
    class ___tostr                                           \
    {                                                        \
        friend class value;                                  \
    private:                                                 \
        struct des{EnumType::___enum e;char* c;}*ptr;        \
        static ___tostr inst;                                \
    protected:                                               \
        explicit ___tostr():ptr(NULL){static struct des __all__[] ={             

#define HELLO_ENUM_STR(enum_item) {enum_item,#enum_item},    


#define HELLO_ENUM_STR_END()                                \
                { ___unkown,"___unkown" }                   \
            };ptr = __all__;                                \
        }                                                   \
    };                                                      \
                                                            \
    const char* value::c_str()const{                        \
        ___tostr::des* iter = ___tostr::inst.ptr;           \
        do{                                                 \
            if(iter->e == ___value) return iter->c;         \
            if(___value == ___unkown) break;                \
            iter++;                                         \
        }while(true);                                       \
        return NULL;                                        \
    }                                                       \
}

#endif