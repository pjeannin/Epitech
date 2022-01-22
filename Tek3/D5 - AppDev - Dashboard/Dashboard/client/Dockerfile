FROM node:lts

WORKDIR /app

COPY package.json yarn.lock ./
RUN yarn install && yarn global add serve

COPY . .
RUN yarn build
EXPOSE 3000
CMD ["serve", "-s", "build"]
