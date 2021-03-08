FROM node:12-alpine

WORKDIR /app
ADD . /app
RUN npm install
EXPOSE 80
ENV PORT 80
CMD ["node", "server.js"]