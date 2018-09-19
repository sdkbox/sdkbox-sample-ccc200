/*!
*@header  CRFilter.h
*Crittercism iOS Library
*@author  Created by Sean Hermany on 7/16/13.
*@copyright  Copyright (c) 2013 Crittercism, Inc. All rights reserved.
*/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, CRFilterType) {
  CRFilterTypeScrubQuery, // Default
  CRFilterTypeBlacklist,
  CRFilterTypePreserveQuery
};

/*!
 @class CRFilter
 Filters can be supplied to Crittercism to adjust the behavior of how URLs are
 captured and reported on for performance monitoring purposes.

 By default, all URLs captured by Crittercism will be reported on when
 performance monitoring is enabled.

 The query portion of URLs will be stripped by default. That is, a request
 for the URL:
 
 https://store.acmecorp.com/purchase?user=wcoyote&ccnum=4444555566667777

 will be reported as: https://store.acmecorp.com/purchase
 
 Filters can either be supplied when Crittercism is enabled, as an array of
 CRFilter objects, or added dynamically at any time.
 
 - Blacklist filters: discard data pertaining to any matching URLs

    [CRFilter filterWithString:@"purchase.php"];

 - Initializing Crittercism with the above filter:

    [Crittercism enableWithAppID:@"YOURAPPID" andConfig:config];
    [Crittercism addFilter:[CRFilter filterWithString:@"purchase.php"]];

 Notes:

 * Filters match URLs via CASE SENSITIVE substring matching

 * Older versions of the agent did not scrub query parameters by default, and
   so a "queryOnlyFilter" existed. To avoid compile time errors for existing
   Crittercism users, this filter type can still be created, but it will be
   ignored by the library. This filter type is deprecated, and will be removed
   in a future version of the agent.
*/

NS_ASSUME_NONNULL_BEGIN

@interface CRFilter : NSObject

@property (readonly, assign) CRFilterType filterType;

#pragma mark - Class Methods

/*!
 *Convenience method to create a blacklisting filter
 *@param matchToken An NSString of the url to filter
 *@return The CRFilter for matchToken
 */
+ (CRFilter *)filterWithString:(NSString *)matchToken;

/*!
 *Convenience method to create a filter which preserves the query portion of
 * Convenience method to create a filter which preserves the query portion of
 */
+ (CRFilter *)queryPreservingFilterWithString:(NSString *)matchToken DEPRECATED_MSG_ATTRIBUTE("Query parameter preservation has been removed. Filters of this type will be ignored. This method will be removed in a future release");

/*!
 *Filter a URL, specifying which type of filter to use.
 *@param filterType CRFilterType specifies the filter type
 *@param url NSString specifies the url
 *@return nil when a blacklist filter is specified.
 */
+ (nullable NSString *)applyFilter:(CRFilterType)filterType ToURL:(NSString *)url;


#pragma mark - Instance Methods

/*!
 *Initialize a filter that blacklists all URLs that match the specified token
 *@param matchToken NSString the of the url to filter
 *@return CRFilter of type CRFilterTypeBlacklist
 */
- (id)initWithString:(NSString *)matchToken;

/*!
 *CRFilter designated initializer
 *@param matchToken NSString the of the url to filter
 *@param filterType CRFilterType indicates filter type CRFilterTypeScrubQuery, CRFilterTypeBlacklist, CRFilterTypePreserveQuery
 *@return CRFilter with the indicated filter type
 */
- (id)initWithString:(NSString *)matchToken
       andFilterType:(CRFilterType)filterType;

/*!
 *Checks if the url matches this filter
 *@param url NSString indicates the url to test
 *@return YES if the url matches, NO if it does not
 */
// Does specified URL match this filter?
- (BOOL)doesMatch:(NSString *)url;

@end

NS_ASSUME_NONNULL_END
