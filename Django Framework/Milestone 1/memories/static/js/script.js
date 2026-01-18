
  const nav = document.querySelector('nav');

  // Function to clear existing popups
  function clearPopups() {
    const existing = document.querySelector('.nav-popup');
    if (existing) existing.remove();
  }

  // Function to create popup content
  function createPopup(content) {
    clearPopups();
    const popup = document.createElement('div');
    popup.className = ' nav-popup m-auto md:w-1/2 sm:w-full p-6 z-50 bg-purple-300 shadow-xl items-center text-center  insert-0  rounded-xl';
    popup.innerHTML = content;
    nav.appendChild(popup);
  }

  // Toggle logic
  function togglePopup(id, content) {
    const existing = document.querySelector('.nav-popup');
    if (existing) {
      // If popup already exists, remove it (vanish)
      clearPopups();
    } else {
      // Otherwise show new popup
      createPopup(content);
    }
  }

  // About click
  document.getElementById('about').addEventListener('click', function(e) {
    e.preventDefault();
    togglePopup('about', `
      <h2 class="text-lg font-semibold mb-2">Recollection — Your Memories, Securely Preserved</h2>
      <p class="text-sm text-gray-700">

Recollection is a personal memory-keeping platform designed to help you capture, store, and relive your most meaningful moments. From simple thoughts and daily experiences to important life events, Recollection gives you a private and secure space where your memories truly belong to you.

Every memory you save is protected behind your personal account. Only you can view, edit, or revisit your recollections after logging in. With a simple registration process and an intuitive interface, Recollection ensures that your memories remain organized, accessible, and safe—anytime you need them.

Whether you want to reflect on the past, track your personal growth, or preserve moments you never want to forget, Recollection is your digital diary, built with privacy, simplicity, and trust at its core.</p>
    `);
  });

  // Contact click
  document.getElementById('contact').addEventListener('click', function(e) {
    e.preventDefault();
    togglePopup('contact', `
      <h2 class="text-lg text-center font-semibold mb-2">Contact Links</h2>
      <ul class="list-none pl-5 text-sm text-gray-700 hover:text-white">
        <li  class="text-black no-underline  hover:text-gray-600 font-semibold md:text-xl text-md">Email : islamohidul856mi647360@gmail.com</li>
        <li><a href="https://www.linkedin.com/in/md-mi/" class="text-black font-semibold no-underline md:text-xl text-md hover:text-white">LinkedIn</a></li>
        <li><a href="https://github.com/mdmohidulislammi/" class="text-black font-semibold no-underline text-md md:text-xl hover:text-white">GitHub</a></li>
      </ul>
    `);
  });
