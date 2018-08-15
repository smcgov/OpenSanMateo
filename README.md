# SMCGOV Drupal Platform

## Table of Contents
* Introduction 
  - Architecture (in progress)
  - Conventions (in progress)
* Compatibility Testing 
* QA (in progress)

## Introduction

This platform is the foundation of a number of the County of San Mateo's department web sites. This codebase is made available as an open source project without any licensing restrictions. 

The platform is a Multi-site, meaning that each of the sites use the same codebase, but have their own databases.
Database config, and each site's unique settings are stored in their settings.php files.

## Two Remotes

Initially, clone the repo from Acquia. This will set it to be the _origin_ remote by default.
Because Acquia doesn't provide tools like code review and pull requests, there is a mirrored repository hosted by Bitbucket.
These repos have to be manually kept in sync.

### origin
Acquia hosts the website, and deployments to Dev, Stage, and Prod are done via pushes to the _origin_ remote.


### Hotfix

A "hotfix" is when a change needs to bypass the integration branch and move directly to Production.
This is usually to fix a critical bug. Follow the same Gitflow outlined above.
Branch off of release and push your branch up to the bitbucket remote.
Create a PR, but instead of integration, select release as the merge target.
Pull down the release branch from bitbucket, create a tag and push it up to acquia:

`git checkout release; git pull bitbucket release; git tag 2016-08-22-A`

Select the release tag using Acquia's dashboard.

Make sure to then merge the release branch into integration and sync with both remotes:

`git checkout integration; git merge release; git push bitbucket integration; git push origin integration`


## Combined Search

Search API is used to populate a node index that is shared between all sites.
All of the sites populate the same Solr Core with their node data.
Search API has the feature of "aggregated fields", which this platform uses heavily.
There are more than a dozen aggregated fields, each of which may accept field info from one or more content type fields.
This is useful, for example, when there are two different date fields from two different content types, yet one view needs to create a listing of both content types.
This aggregated field might be called "search_api_multi_aggregation_9", for example, though it is basically the same as if it was stored in Search API as its native date field.

#### Site ID
A unique hash is generated for each site as it is indexed.
This field is stored in the search index, so that each indexed item can report which site it belongs to.
This is used in the custom Views filter to show items from all sites, or "this site only".

#### Images
Images are preprocessed using custom code before being indexed by Search API in order to store an absolute URL to the re-sized image.
This is because when displaying search results, any given site only has access to the result's site hash, and not its actual URL.
Also, when a custom Image Size is generated for an image, a unique query hash is used by Drupal to prevent DDOS attacks, and the site needs to generate this the first time an image size is used.

## Continued Compatibility Testing

As a public agency we are responsible for testing new features and development on a range of current and legacy browser environments through desktop and mobile devices. We are also responsbile for usability and accessibility testing to ensure our users and consistently served by our resouces. We employ a range of tools to keep up standards for content over 22 department/agency sites, and over 100 content managers.

#### Tools
![BrowserStack Logo](https://p14.zdusercontent.com/attachment/1015988/OuLhxwxzAlSVoSsydpEACDsCP?token=eyJhbGciOiJkaXIiLCJlbmMiOiJBMTI4Q0JDLUhTMjU2In0..QYHMsaMrd6pD8Ic55IjqGg.1KkBjb65xpKaG4IAjBWOgzNdSkWbZp3rblq_GdSLnnlFrPPdca76LRYvdLsbT0AM38TGUwNDXcLha4_fFxW2nKl4m5OBUS7E45Exv82ueSnVqUgDswwcUJdlU5327bQ_QJeXzDdB4pPoY2cGSL-QYGutjZsrLoLRj_vXywGdDP8JzRDSUOtqzK03DpEs2nRnzIib4JXrY5n7jhUmkzAd1_yFcCustQLg4xPERP9d4vYXLm3TpVQHj7uZs1oZQjy7Xlyvxve75iK-GseWM0p60Ry4pEZQVBqJCiCaoOHJrUA.sey2fqh67W7NfzLsA_eEaQ)
[BrowserStack](https://www.browserstack.com/)
