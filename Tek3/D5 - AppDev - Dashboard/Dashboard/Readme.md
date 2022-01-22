# Dashboard

The Dashboard project is a web application that acts as an administration panel for your own life. On your dashboard you can create widgets linked to different service accounts (youtube, twitter, github, ...) allowing you to display some information about them.

## Installation and setup

The dashboard project contains 3 separate applications :

- a React front-end app
- an Express back-end app
- a MongoDB database

In order to launch the project, you must add an express.env, mongodb.env and react.env files in a env folder at the root of the project with the following configuration :

### Express Env :

```
PORT (port of your app)
MONGOURL (connection string to your mongo database)
TOKENSECRET (token secret for password hash)
APIKEYWEATHER (weatherapi.com api key)
APIKEYYOUTUBE (youtube api key)
APPIDREDDIT (app id for reddit oauth)
REDIRECTURIREDDIT (redirect uri from reddit oauth app)
```

### MongoDB Env :

```
MONGO_INITDB_ROOT_USERNAME (mongodb username)
MONGO_INITDB_ROOT_PASSWORD (mongodb password)
```

### React Env :

DISCLAIMER : react.env file is not working properly, so you need to put your env variables in the json/config.json file.

```
EXPRESSADDR (address of the express server)
```

You will also need to install docker if you want to setup the application in a docker environment.

Once done, you can launch the project with the following command:

`docker-compose build && docker-compose up`

The applications will be available on the following ports without modifications from you:

React : 3000<br>
Express : 8080<br>
MongoDB : 27017<br>

## Create a new widget

To create a new widget, you need to create the needed route in the back-end app and the corresponding widget in the front-end app.

In the front-end app, in the Widget.js file, there is a switch case which return the right widget according to the service name and the widget name. You juste have to create a component for each new widget you want. The only requirement si to have a getData() method which set your widget data in the state of the widget. This function has to be called in the componentDidMount() method of the component to initialize the widget.

In the back-end app, you need to create a route for update the widget in order to avoid api key in the front-end app. This route is in the routes/update.js file.

## Create a new service in database

To create a new service, you must use both routes /api/widgets/createService and /api/widgets/addWidgetService.

/api/widgets/createService is used to create a new service in a database with an initial widget. You must provide a
service name with a widget object. Informations can be found in the API documentation.

/api/widgets/addWidgetService is used to add a widget to an existing service. You must provide a widget object.
Informations can be found in the API documentation.