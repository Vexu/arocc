// Tests to make sure that __has_extension can be used on features as well
// (extensions are a superset of features).

#if !__has_feature(attribute_deprecated_with_message)
#error expected attribute_deprecated_with_message to be available as a feature
#endif

#if !__has_extension(attribute_deprecated_with_message)
#error expected attribute_deprecated_with_message to be available as an extension
#endif

/** manifest:
syntax

*/
