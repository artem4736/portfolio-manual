(function () {
  const btn = document.getElementById('themeToggle');
  const sun = document.getElementById('sun');
  const moon = document.getElementById('moon');
  const root = document.documentElement;

  function syncIcons() {
    const isDark = root.classList.contains('dark');
    sun.classList.toggle('icon-visible', isDark);
    sun.classList.toggle('icon-hidden', !isDark);
    moon.classList.toggle('icon-visible', !isDark);
    moon.classList.toggle('icon-hidden', isDark);
  }

  syncIcons();

  btn.addEventListener('click', () => {
    const nowDark = root.classList.toggle('dark');
    try {
      localStorage.setItem('theme', nowDark ? 'dark' : 'light');
    } catch (e) {}

    if (window.gsap) {
      const fadeOut = nowDark ? moon : sun;
      const fadeIn = nowDark ? sun : moon;
      gsap.to(fadeOut, {
        opacity: 0,
        scale: 0.7,
        duration: 0.18,
        onComplete: () => {
          syncIcons();
          gsap.fromTo(
            fadeIn,
            { opacity: 0, scale: 0.7 },
            { opacity: 1, scale: 1, duration: 0.22 }
          );
        },
      });
    } else {
      syncIcons();
    }
  });

  // Бургер меню
  const burger = document.getElementById('burger');
  const menu = document.querySelector('nav ul');
  burger.addEventListener('click', () => {
    menu.classList.toggle('show');
  });

  // Lightbox
  const lightbox = document.getElementById('lightbox');
  const lightboxImg = document.getElementById('lightbox-img');
  document.querySelectorAll('.award-img').forEach((img) => {
    img.addEventListener('click', () => {
      lightboxImg.src = img.src;
      lightbox.classList.remove('hidden');
      lightbox.classList.add('flex');
    });
  });

  lightbox.addEventListener('click', () => {
    lightbox.classList.add('hidden');
    lightbox.classList.remove('flex');
  });
})();