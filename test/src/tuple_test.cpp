#include <gmock/gmock.h>

#include <tuple/tuple.hpp>


using namespace ::testing;

namespace nonstd
{
namespace tuples
{

TEST(tuple, can_contain_primitive_variables)
{
	tuple<int, char> t;

	t.element0 = 10;
	t.element1 = 'a';

	ASSERT_THAT(t.element0, Eq(10));
	ASSERT_THAT(t.element1, Eq('a'));
}


TEST(tuple_constructor, accepts_element_values)
{
	tuple<int, char> t(10, 'a');

	ASSERT_THAT(t.element0, Eq(10));
	ASSERT_THAT(t.element1, Eq('a'));
}


TEST(tuple_get, allows_element_access_with_index)
{
	tuple<int, char> t(10, 'a');

	ASSERT_THAT(t.get<0>(), Eq(10));
	ASSERT_THAT(t.get<1>(), Eq('a'));
}


TEST(tuple_get, returns_reference_to_element)
{
	tuple<int> t(10);

	t.get<0>() = 1;

	ASSERT_THAT(t.get<0>(), Eq(1));
}


TEST(tuple_get, returns_const_reference_to_element)
{
	const tuple<int> t(10);

	ASSERT_THAT(t.get<0>(), Eq(10));
}


TEST(tuple_construct, with_default_arguments_null)
{
	tuple<int> t(10);

	ASSERT_THAT(t.get<0>(), Eq(10));
}


TEST(tuple_construct, with_5_arguments)
{
	tuple<std::string, int, short, long, char> t("tuple", 1, 2, 3, '4');

	ASSERT_THAT(t.get<0>(), Eq("tuple"));
	ASSERT_THAT(t.get<1>(), Eq(1));
	ASSERT_THAT(t.get<2>(), Eq(2));
	ASSERT_THAT(t.get<3>(), Eq(3));
	ASSERT_THAT(t.get<4>(), Eq('4'));
}


} // namespace tuples.
} // namespace nonstd.
