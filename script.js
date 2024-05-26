const carousel = document.querySelector('.carousel');
const prevBtn = document.querySelector('.prev');
const nextBtn = document.querySelector('.next');
let counter = 0;

function updateCarousel() {
    carousel.style.transform = `translateX(${-counter * 100}%)`;
}

prevBtn.addEventListener('click', () => {
    counter = Math.max(0, counter - 1);
    updateCarousel();
});

nextBtn.addEventListener('click', () => {
    counter = Math.min(1, counter + 1);
    updateCarousel();
});
