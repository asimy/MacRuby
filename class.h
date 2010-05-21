/*
 * This file is covered by the Ruby license. See COPYING for more details.
 * 
 * Copyright (C) 2010, Apple Inc. All rights reserved.
 */

#ifndef __CLASS_H_
#define __CLASS_H_

#if defined(__cplusplus)
extern "C" {
#endif

#define RCLASS_IS_OBJECT_SUBCLASS    (1<<1)  /* class is a true RubyObject subclass */
#define RCLASS_IS_RUBY_CLASS         (1<<2)  /* class was created from Ruby */
#define RCLASS_IS_MODULE             (1<<3)  /* class represents a Ruby Module */
#define RCLASS_IS_SINGLETON	     (1<<4)  /* class represents a singleton */
#define RCLASS_IS_FROZEN	     (1<<5)  /* class is frozen */
#define RCLASS_IS_TAINTED	     (1<<6)  /* class is tainted */
#define RCLASS_IS_INCLUDED           (1<<10)  /* module is included */
#define RCLASS_HAS_ROBJECT_ALLOC     (1<<11)  /* class uses the default RObject alloc */
#define RCLASS_SCOPE_PRIVATE	     (1<<12)  /* class opened for private methods */
#define RCLASS_SCOPE_PROTECTED	     (1<<13)  /* class opened for protected methods */
#define RCLASS_SCOPE_MOD_FUNC	     (1<<14)  /* class opened for module_function methods */
#define RCLASS_KVO_CHECK_DONE	     (1<<15)  /* class created by KVO and flags merged */

unsigned long rb_class_get_flags(Class k);
void rb_class_set_flags(Class k, unsigned long flags);

#define RCLASS_VERSION(m) (rb_class_get_flags((Class)m))
#define RCLASS_SET_VERSION(m,f) (rb_class_set_flags((Class)m, (unsigned long)f))
#define RCLASS_SET_VERSION_FLAG(m,f) (RCLASS_SET_VERSION((Class)m, (RCLASS_VERSION(m) | f)))

#define RCLASS_RUBY(m) ((RCLASS_VERSION(m) & RCLASS_IS_RUBY_CLASS) == RCLASS_IS_RUBY_CLASS)
#define RCLASS_MODULE(m) ((RCLASS_VERSION(m) & RCLASS_IS_MODULE) == RCLASS_IS_MODULE)
#define RCLASS_SINGLETON(m) ((RCLASS_VERSION(m) & RCLASS_IS_SINGLETON) == RCLASS_IS_SINGLETON)

CFMutableDictionaryRef rb_class_ivar_dict(VALUE);
CFMutableDictionaryRef rb_class_ivar_dict_or_create(VALUE);
void rb_class_ivar_set_dict(VALUE, CFMutableDictionaryRef);

#if defined(__cplusplus)
} // extern "C"
#endif

#endif // __CLASS_H_