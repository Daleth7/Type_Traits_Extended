#ifndef CPLSUPLUS_TYPE_TRAITS_EXTENSION___HHH____
#define CPLSUPLUS_TYPE_TRAITS_EXTENSION___HHH____

namespace Type_Trait{
    /*  conditional<typename ToF_Type, typename T, typename F>,
        like its standard counterpart, provides either type T
        or F depending on ToF_Type.

        Template Parameters:
            * ToF_Type - either std::true_type or std::false_type
            * T - member type if ToF_Type is std::true_type
            * F - member type if ToF_Type is std::false_type
        Members:
            * type - Either T or F depending on ToF_Type being
                std::true_type or std::false_type, respectively.

        Example use:
                //Creates an int type variable
            Type_Trait::conditional<
                std::is_same<int, int>::type,   //Condition
                int, char                       //Types to resolve to
                >::type var;
                //Creates a char type variable
            conditional<std::is_same<double, int>::type, int, char>::type var;
    */
    template <typename ToF_Type, typename T, typename F>
        struct conditional;

    /*  any_true<T1, Tn...> takes a list of std::integral_constant
        instantiations and determines if any of them is std::true_type.
        At least one parameter must be provided.

        Template Parameters:
            * T1 - a std::integral_constant instantiation
            * Tn... - additional instantiations
        Members:
            * type - equivalent to std::true_type if at least one of the
                parameters is std::true_type. std::false_type otherwise.

        Example use:
            typedef std::true_type tt;
            typedef std::false_type ft;
                //Creates a char type variable
            Type_Trait::conditional<
                Type_Trait::any_true<ft, ft, ft, ft, ft, ft, ft, tt>::type,
                int, char
            > var;
    */
    template <typename T1, typename... Tn>
        struct any_true;


    /*  count_matches<T1, T2, Tn...> takes type T1 and compares it to
        the rest of the parameter list, counting the total number of
        types that match it. At least two parameters must be provided.

        Template Parameters:
            * T1 - the type to check for
            * T2 - the first type to check against
            * Tn... - additional types to check against
        Members:
            * type - equivalent to std::true_type if at least one match
                is found. std::false_type otherwise.
            * match - a std::size_t variable that stores the number of
                matches found.

        Example use:
            assert(Type_Trait::count_matches<int, int, char, int>::match == 2);
    */
    template <typename T1, typename T2, typename... Tn>
        struct count_matches;



    /*  find_base<Derived, BaseN...> looks for the first type in the BaseN
        parameter pack that is a base type of Derived. Note that only the
        first result is found and retrievable. If none of the types is a
        base type of Derived or there is no BaseN list provided, the member
        type will be equivalent to Derived.

        Template Parameters:
            * Derived - the type whose base is looked for
            * BaseN... - the list of types to check
        Members:
            * type - equivalent to std::true_type if a base type was found.
                std::false_type otherwise.
            * base - the type of the first result that is a base type of
                Derived. If no match was found or no list was provided,
                this type is equivalent to Derived.

        Example use:
            assert(Type_Trait::count_matches<int, int, char, int>::match == 2);
    */
    template <typename Derived, typename... BaseN>
        struct find_base;
}

#include "Type_Traits_Ext.inl"

#endif