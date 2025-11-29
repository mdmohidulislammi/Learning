/** @type {import('tailwindcss').Config} */
module.exports = {
  content: [
    "./templates/**/*.html"  ,//Templates at the project
    "./**/templates/**/*.html"  //inside the app
  ],
  theme: {
    extend: {},
  },
  plugins: [],
}

