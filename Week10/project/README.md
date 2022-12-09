# Hot Stocks

- Micheline Doughlin
- Ben Sjostrom
- York Shaw
- Karis Courey

Hot Stocks - revolutionizing stocks to make them, like, totally cool.

## Video demo: <https://www.youtube.com/watch?v=aVcRNvSrzWg>
## Source code: <https://gitlab.com/igneous-rocks/hot-stocks/>

## Description

### Design

#### API design

##### Authentication

###### Get Token

* Endpoint path: /token
* Endpoint method: GET

* Response: Account information and a token
* Response shape (JSON):
    ```json
    {
      "access_token": string,
      "token_type": string,
      "account": {
        "id": string,
        "username": string,
        "email": string
      }
    }
    ```

###### Login

* Endpoint path: /token
* Endpoint method: POST

* Request shape (JSON):
    ```json
    {
      "username": string,
      "password": string,
    }
    ```

* Response: Account information and a token
* Response shape (JSON):
    ```json
    {
      "access_token": string,
      "token_type": string
    }
    ```

###### Logout

* Endpoint path: /token
* Endpoint method: DELETE

* Headers:
  * Authorization: Bearer token

* Response: Always true
* Response shape (JSON):
    ```json
    true
    ```

###### Create Account

* Endpoint path: /accounts
* Endpoint method: POST

* Request shape (JSON):
  ```json
  {
    "username": string,
    "email": string,
    "password": string,
  }
  ```

* Response: Account information and a token, only returned if password == confirm_password
* Response shape (JSON):
    ```json
    {
      "access_token": string,
      "token_type": string,
      "account": {
        "id": string,
        "username": string,
        "email": string,
      }
    }
    ```


##### Portfolio stocks

###### Get All Portfolio Stocks

* Endpoint path: /portfolio_stocks
* Endpoint method: GET

* Headers:
  * Authorization: Bearer token

* Response: A list of portfolio stocks
* Response shape (JSON):
    ```json
    {
      "portfolio_stocks": [
        {
          "id": number,
          "account_id": number,
          "symbol": string,
          "num_shares": number,
          "cost_basis": number
        }
      ]
    }
    ```

###### Create or Update Portfolio Stock

* Endpoint path: /portfolio_stocks/
* Endpoint method: POST

* Headers:
  * Authorization: Bearer token

* Request shape (JSON):
    ```json
    {
      "symbol": string,
      "num_shares": number,
      "cost_basis": number,
    }
    ```

* Response: A detail of portfolio stock
* Response shape (JSON):
    ```json
    {
      "id": number,
      "account_id": number,
      "symbol": string,
      "num_shares": number,
      "cost_basis": number
    }

###### Delete Portfolio Stock

* Endpoint path: /portfolio_stocks/`<int:id>`
* Endpoint method: DELETE
* Query Parameters:
  * portfolio_stock_id

* Headers:
  * Authorization: Bearer token

* Response: A detail of portfolio stock
* Response shape (JSON):
    ```json
    {
      "success": boolean
    }
    ```


##### Saved news items

###### Get All Saved News Items

* Endpoint path: /saved_news_items
* Endpoint method: GET

* Headers:
  * Authorization: Bearer token

* Response: An list of saved news items
* Response shape:
    ```json
    {
      "news_items":[
        {
          "id": number,
          "account_id": number,
          "title": string,
          "news_url": string,
          "time_published": string,
          "banner_image": string,
          "summary": string,
          "preference": boolean
        }
      ]
    }


###### Create Or Update Saved News Item

* Endpoint path: /saved_news_items/
* Endpoint method: POST

* Headers:
  * Authorization: Bearer token

* Request shape (JSON):
    ```json
    {
      "title": string,
      "news_url": string,
      "time_published": string,
      "banner_image": string,
      "summary": string,
      "preference": boolean
    }
    ```

* Response: A detail of saved news item
* Response shape (JSON):
    ```json
    {
      "id": number,
      "account_id": number,
      "title": string,
      "news_url": string,
      "time_published": string,
      "banner_image": string,
      "summary": string,
      "preference": boolean
    }


###### Delete Saved News Item

* Endpoint path: /saved_news_items/`<int:id>`
* Endpoint method: DELETE
* Query Parameters:
  * news_item_id

* Headers:
  * Authorization: Bearer token

* Response: An indication of success or failure
* Response shape (JSON):
    ```json
    {
      "success": boolean
    }
    ```


##### Saved stocks

###### Get All Saved Stocks

* Endpoint path: /saved_stocks
* Endpoint method: GET

* Headers:
  * Authorization: Bearer token

* Response: An list of saved stocks
* Response shape (JSON):
    ```json
    {
      "saved_stocks":[
        {
          "id": number,
          "account_id": number,
          "symbol": string,
          "preference": boolean
        }
      ]
    }

###### Create Or Update Saved Stock

* Endpoint path: /saved_stocks/
* Endpoint method: POST

* Headers:
  * Authorization: Bearer token

* Request shape (JSON):
    ```json
    {
      "symbol": string,
      "preference": boolean
    }
    ```

* Response: A detail of saved stock
* Response shape (JSON):
    ```json
    {
      "id": number,
      "account_id": number,
      "symbol": string,
      "preference": boolean
    }
    ```


###### Delete Saved Stock

* Endpoint path: /saved_stocks/`<int:id>`
* Endpoint method: DELETE
* Query Parameters:
  * saved_stock_id

* Headers:
  * Authorization: Bearer token

* Response: An indication of success or failure
* Response shape (JSON):
    ```json
    {
      "success": boolean
    }
    ```


##### External-API-interfacing endpoints

###### Get Company

* Endpoint path: /companies/`<str:symbol>`/
* Endpoint method: GET
* Query Parameters:
  * symbol

* Headers:
  * Authorization: Alphavantage token

* Response: A detail of stock
* Response shape (JSON):
    ```json
    {
      "company":
        {
          "symbol": string,
          "name": string,
          "description": string
        }
    }
    ```

###### Get Stock

* Endpoint path: /stocks/`<str:symbol>`/
* Endpoint method: GET
* Query Parameters:
  * symbol

* Headers:
  * Authorization: Alphavantage token

* Response: A detail of stock
* Response shape (JSON):
    ```json
    {
      "stock": [
        {
          string: string
        }
      ]
    }
    ```

###### Get All Stocks

* Endpoint path: /stocks
* Endpoint method: GET

* Headers:
  * Authorization: Bearer token

* Response: A list of stocks
* Response shape (JSON):
    ```json
    {
      "stocks":[
        {
          "symbol": string,
          "name": string,
          "cost_current": number
        }
      ]
    }

###### Get All News Items

* Endpoint path: /news_items
* Endpoint method: GET

* Headers:
  * Authorization: Alphavantage token

* Response: A list of news items
* Response shape (JSON):
    ```json
    {
      "news_items": [
        {
          "title": string,
          "news_url": string,
          "time_published": string,
          "summary": string,
          "banner_image": string
        }
      ]
    }
    ```


#### Data model
##### Data models

##### Hot Stocks monolith

---

##### Account

| name             | type   | unique | optional |
| ---------------- | ------ | ------ | -------- |
| id               | int    | yes    | no       |
| user_name        | string | yes    | no       |
| email            | string | yes    | no       |
| hashed_password  | string | no     | no       |




##### Portfolio stock

| name       | type            | unique | optional |
| -------    | --------------- | ------ | -------- |
| id         | int             | yes    | no       |
| account_id | ref to account  | yes    | no       |
| symbol     | string          | no     | yes      |
| num_shares | int             | no     | yes      |
| cost_basis | float           | no     | yes      |

Unique constraint on account_id, symbol.



##### Saved news item

| name             | type            | unique | optional |
| ---------------- | --------------- | ------ | -------- |
| id               | int             | yes    | no       |
| account_id       | ref to account  | yes    | no       |
| title            | string          | no     | yes      |
| news_url         | string          | no     | yes      |
| time_published   | string          | no     | yes      |
| banner_image     | string          | no     | yes      |
| summary          | string          | no     | yes      |
| preference       | bool            | no     | yes      |

Unique constraint on account_id, news_url.


##### Saved stock

| name       | type            | unique | optional |
| -------    | --------------- | ------ | -------- |
| id         | int             | yes    | no       |
| account_id | ref to account  | yes    | no       |
| symbol     | string          | no     | yes      |
| preference | bool            | yes    | yes      |

Unique constraint on account_id, symbol.


#### Integrations
##### Integrations

The application will need to get the following kinds of data from third-party sources:

- Stocks data from Alpha Vantage API
- Stocks data from Financial Modeling Prep API


### Intended market

Our key demographic are men and women that are in the age range of 18 - 42. Our target audience are those that are interested in investing in stocks and growing their portfolio.


### Functionality

- When users access the app they will have the option to sign up for an account if they do not have one.
- Users will have the ability to cycle through stocks and finance new articles on the explore page.  From this page users can:
  - Save news items and stocks to their saved folder
  - Add stock to portfolio
- The search page allows for users to search and stocks and news articles will show that contain the searched word
- The saved page is where users can access the stocks and news articles that they saved
- Portfolio will have the stocks that user has ___
- About Page has logo and information about the hot stocks app

### Project Initialization

To fully enjoy this application on your local machine, please make sure to follow these steps:

1. Clone the repository down to your local machine
2. CD into the new project directory
3. Run `docker volume hot-stocks`
4. Run `docker compose build`
5. Run `docker compose up`
6. Enjoy Hot Stocks to its fullest!
