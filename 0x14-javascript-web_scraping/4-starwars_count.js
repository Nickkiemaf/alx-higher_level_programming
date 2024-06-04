#!/usr/bin/node

const request = require('request');
const apiUrl = process.argv[2];
const wedgeAntillesId = 18;

request(apiUrl, (error, response, body) => {
  if (error) {
    console.error('Error:', error);
  } else if (response.statusCode !== 200) {
    console.error('Failed to retrieve data:', response.statusCode);
  } else {
    const films = JSON.parse(body).results;
    const wedgeMovies = films.filter(film => film.characters.includes(`https://swapi-api.alx-tools.com/api/people/${wedgeAntillesId}/`));
    console.log(wedgeMovies.length);
  }
});
