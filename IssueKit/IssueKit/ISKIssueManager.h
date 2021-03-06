//
//  ISKIssueManager.h
//  IssueKit
//
//  Created by Mert Dümenci on 6/26/13.
//  Copyright (c) 2013 Mert Dumenci. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ISKGitHubIssueAPIClient.h"
#import "ISKImgurAPIClient.h"

#define kIssueLabel @"IssueKit"
#define kIssueColor @"3f61ff"

@interface ISKIssueManager : NSObject

@property (nonatomic, readonly) NSString *reponame;
@property (nonatomic, retain) UITapGestureRecognizer *tapGestureRecognizer;

+ (instancetype)defaultManager;

/*
    The repo name must be in username/repo format.
    Get an API Access Token from https://github.com/settings/applications
 */

- (void)setupWithReponame:(NSString *)reponame andAccessToken:(NSString *)accessToken;

/*
    Image uploads are optional.
    If you want to utilize them, get an imgur client ID by registering your application as 'anonymous' here:
    http://api.imgur.com/oauth2/addclient
*/

- (void)setupImageUploadsWithClientID:(NSString *)clientID;
- (void)createNewIssueWithTitle:(NSString *)title body:(NSString *)body success:(IssueCreateBlock)successBlock error:(IssueErrorBlock)errorBlock;
- (void)createNewIssueWithTitle:(NSString *)title body:(NSString *)body image:(UIImage *)image success:(IssueCreateBlock)successBlock error:(IssueErrorBlock)errorBlock;


- (void)presentIssueViewControllerOnViewController:(UIViewController *)viewController;

/*
    Experimental feature which installs a 3-finger-double-tap gesture on UIWindow.
*/

- (void)installGestureOnWindow:(UIWindow *)window;

- (BOOL)hasImageUploads;

@end
