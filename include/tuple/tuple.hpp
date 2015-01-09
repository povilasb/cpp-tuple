#ifndef NONSTD_TUPLE_HPP
#define NONSTD_TUPLE_HPP


namespace nonstd
{
namespace tuples
{

// Forward declarations.
namespace impl
{

template <typename T0, typename T1, typename T2, typename T3, typename T4,
	int N>
struct element_getter;

// Null tuple element used for unused tuple arguments.
struct null_element_type {};
static null_element_type null_element;

} // namespace impl.


/**
 * Tuple template class with minimum of one argument and maximum of 5 arguments.
 */
template <typename T0, typename T1 = impl::null_element_type,
	typename T2 = impl::null_element_type,
	typename T3 = impl::null_element_type,
	typename T4 = impl::null_element_type>
struct tuple {
	T0 element0;
	T1 element1;
	T2 element2;
	T3 element3;
	T4 element4;

	/**
	 * Constructs tuple with uninitialized element values.
	 */
	tuple()
	{
	}


	tuple(T0 _element0, T1 _element1 = impl::null_element,
		T2 _element2 = impl::null_element,
		T3 _element3 = impl::null_element,
		T4 _element4 = impl::null_element)
		: element0(_element0), element1(_element1),
		element2(_element2), element3(_element3)
		, element4(_element4)
	{
	}


	/**
	 * Returns reference to N'th tuple element allowing to change it's
	 * value.
	 */
	template <int N>
	typename impl::element_getter<T0, T1, T2, T3, T4, N>::element_type&
	get()
	{
		return impl::element_getter<T0, T1, T2, T3, T4, N>::get(*this);
	}


	/**
	 * Returns const reference to N'th tuple element.
	 */
	template <int N>
	const typename impl::element_getter<T0, T1, T2, T3, T4, N>::element_type&
	get() const
	{
		return impl::element_getter<T0, T1, T2, T3, T4, N>::get_const(*this);
	}

};


namespace impl
{

template <typename T0, typename T1, typename T2, typename T3, typename T4,
	int N>
struct element_getter;


/**
 * Defines specialized element_getter structure which returns tuple element
 * by the specified element number.
 */
#define DEFINE_TUPLE_ELEMENT_GETTER(element_nr) \
template <typename T0, typename T1, typename T2, typename T3, typename T4> \
struct element_getter<T0, T1, T2, T3, T4, element_nr> { \
\
	typedef T ## element_nr element_type; \
\
	static element_type& \
	get(tuple<T0, T1, T2, T3, T4>& tuple) \
	{ \
		return tuple.element ## element_nr; \
	} \
	\
	static const element_type& \
	get_const(const tuple<T0, T1, T2, T3, T4>& tuple) \
	{ \
		return tuple.element ## element_nr; \
	} \
};

DEFINE_TUPLE_ELEMENT_GETTER(0)
DEFINE_TUPLE_ELEMENT_GETTER(1)
DEFINE_TUPLE_ELEMENT_GETTER(2)
DEFINE_TUPLE_ELEMENT_GETTER(3)
DEFINE_TUPLE_ELEMENT_GETTER(4)

} // namespace impl.

} // namespace nonstd.
} // namespace tuples.


#endif /* NONSTD_TUPLE_HPP */
