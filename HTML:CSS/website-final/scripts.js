//floating top navbar
let navbar = document.querySelector('.topnav');
document.addEventListener('scroll', () => {
    if (window.top.scrollY > 19) {
        navbar.classList.add('scroll');
    } else {
        navbar.classList.remove('scroll');
    }
});

//fade in text on scrolling
window.onload = fadeIn; 
          
        function fadeIn() { 
            var fade = document.getElementById("fading"); 
            var opacity = 0; 
            var intervalID = setInterval(function() { 
          
                if (opacity < 1) { 
                    opacity = opacity + 0.2
                    fade.style.opacity = opacity; 
                } else { 
                    clearInterval(intervalID); 
                } 
            }, 200); 
        };

//fade text when scrolling
const items = document.querySelectorAll('.appear2');
const active = function(entries){
    entries.forEach(entry => {
        if(entry.isIntersecting){
        entry.target.classList.add('inview2'); 
        }else{
            entry.target.classList.remove('inview2'); 
        }
    });
}
const io2 = new IntersectionObserver(active);
 for(let i=0; i < items.length; i++){
    io2.observe(items[i]);
 };

